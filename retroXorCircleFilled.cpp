/* :ts=4
 *  $VER: retroXorCircleFilled.c $Revision$ (16-May-2018)
 *
 *  This file is part of retromode.
 *
 *  Copyright (c) 2018 LiveForIt Software.
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

/****** retromode/main/retroXorCircleFilled ******************************************
*
*   NAME
*      retroXorCircleFilled -- Description
*
*   SYNOPSIS
*      void retroXorCircleFilled(struct retroScreen * screen, int x, int y, 
*          int r, unsigned char xor_mask);
*
*   FUNCTION
*
*   INPUTS
*       screen - 
*       x - 
*       y - 
*       r - 
*       xor_mask - 
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

void retroXorCircleFilled(
       struct retroScreen * screen,
       int cx,
       int cy,
       int r,
       unsigned char xor_mask)
{

	int x0,y0,x1,y1,_y;
	int xx;
	int r2 = r * r;
	int x,y;
	unsigned char *memory;

	y0 = cy-r;
	y1 = cy+r;

	if (y0<0) y0=0;
	if (y1>screen->realHeight-1) y1 = screen->realHeight-1;

	memory = screen -> Memory[screen -> double_buffer_draw_frame] + (screen -> realWidth * y0);

	for (y=y0;y<=y1;y++)
	{
		_y = y - cy; 

		xx = sqrt( r2 - (_y*_y));

		x0 = cx -xx;
		x1 = cx +xx;

		if (x0<0) x0 = 0;
		if (x1>screen->realWidth-1) x1 = screen -> realWidth-1;

		for (x = x0; x <= x1; x++)
		{
			memory[ x ] ^= xor_mask;
		}

		memory += screen -> realWidth;
	}
}

