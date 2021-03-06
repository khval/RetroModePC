/* :ts=4
 *  $VER: retroPolyLine.c $Revision$ (27-Oct-2017)
 *
 *  This file is part of retromode.
 *
 *  Copyright (c) 2017 LiveForIt Software.
 *  MIT License.
 *
 * $Id$
 *
 * $Log$
 *
 *
 */

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <retromode.h>
#include <retromode_lib.h>
#include <stdarg.h>
#include <math.h>

/****** retromode/main/retroPolyLine ******************************************
*
*   NAME
*      retroPolyLine -- Description
*
*   SYNOPSIS
*      void retroPolyLine(struct retroScreen * screen, unsigned char color, ... );
*
*   FUNCTION
*
*   INPUTS
*       screen - screen to draw to.
*       color - the color to use
*       ... - list of (x,y) points, last item should be "retroEnd"
*
*   RESULT
*       This function does not return a result
*
*   EXAMPLE
*
*	retroPolyLine( screen, color,   10,10,   50,20,   50,50,   retroEnd );
*
*   NOTES
*
*   BUGS
*
*   SEE ALSO
*
*****************************************************************************
*
*/

void retroLine( struct retroScreen * screen, int x1, int y1, int x2, int y2, unsigned char color);

void retroPolyLine(
       struct retroScreen * screen,
       unsigned char color,
        ...)
{
	va_list list;



	int x=0,y=0,lx=0,ly=0;
	int i = 0, count = 0;

	va_start(list,color);

	// --- START BUG fix

	x = va_arg(list,int);
	for (i=0;i<2;i++)
	{
		x = va_arg(list,int);
		x = va_arg(list,int);
	}

	// --- END BUG fix


	i = 0;
	do
	{
		if ( ! ( i &1) ) 
		{
			lx = x;
			x = va_arg(list,int);
		}
		else
		{
			ly = y;
			y = va_arg(list,int);	
			count ++;

			if (count > 1 )
			{
				retroLine( screen, lx, ly, x, y, color);
			}
		}
		i++;
		
	} while (( x != retroEnd) && ( y != retroEnd) ) ;
	va_end(list);
}

