/* :ts=4
 *  $VER: retroPolyGon.c $Revision$ (27-Oct-2017)
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

//#include <libbase.h>

/****** retromode/main/retroPolyGon ******************************************
*
*   NAME
*      retroPolyGon -- Description
*
*   SYNOPSIS
*      void retroPolyGon(struct retroScreen * screen, unsigned char color, 
*           ...);
*
*   FUNCTION
*
*   INPUTS
*       screen - 
*       color - 
*       ... - 
*
*   RESULT
*       This function does not return a result
*
*   EXAMPLE
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

extern void retroPolyGonArray(
	struct retroScreen * screen,
	unsigned char color, 
	int array_size,
	int * array);


void retroPolyGon(
       struct retroScreen * screen,
       unsigned char color,
        ...)
{
	va_list list;

	int array_size;
	int array[100*2];

	va_start(list, color );

	{
		int x,n;

		// --- START BUG fix
		x = va_arg(list,int);
		for (n=0;n<2;n++)
		{
			x = va_arg(list,int);
			x = va_arg(list,int);
		}
		// --- END BUG fix

		n = 0;
		do
		{
			array[n] = va_arg(list,int);
			n++;
		} while (( array[n-1] != retroEnd) ) ;
		va_end(list);

		array_size = n-1;
	}

	retroPolyGonArray(Self, screen, color, array_size, array);

}

