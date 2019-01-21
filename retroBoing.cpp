/* :ts=4
 *  $VER: retroBoing.c $Revision$ (02-Nov-2017)
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

/****** retromode/main/retroBoing ******************************************
*
*   NAME
*      retroBoing -- Description
*
*   SYNOPSIS
*      void retroBoing(struct retroScreen * screen, int x, int y, int r0, 
*          int r1, unsigned char color0, unsigned char color1);
*
*   FUNCTION
*
*   INPUTS
*       screen - 
*       x - 
*       y - 
*       r0 - 
*       r1 - 
*       color0 - 
*       color1 - 
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

void retroPixel( struct retroScreen * screen, int x, int y,  unsigned char color);

void retroBoingOutline(  struct retroScreen *screen, int rx, int ry, int r, int t, unsigned char color )
{
	int x0,y0,x1,y1;
	int xx;
	int rr;
	int r2 = r * r;
	int x,y;

	x0 = rx -r;
	y0 = ry-r;
	x1 = rx+r;
	y1 = ry+r;

	for (y=-r;y<=r;y++)
	{
		xx = sqrt( r2 - (y*y));

		for (x = -xx; x<xx;x++)
		{
			rr = sqrt( (x*x) + (y*y) );

			if (rr<=r)
			{
				retroPixel( screen, x + rx, y + ry, rr<r-t ? 2 : color );
			}
		}
	}
}

void retroBoing(  struct retroScreen *screen, int rx, int ry, int r, unsigned char color )
{
	int x0,y0,x1,y1;
	int xx;
	int r2 = r * r;
	int width, height;
	int bx,by;
	int x,y;

	x0 = rx -r;
	y0 = ry-r;
	x1 = rx+r;
	y1 = ry+r;

	height = y1-y0+1;

	for (y=-r;y<=r;y++)
	{
		xx = sqrt( r2 - (y*y));
		width = xx*2+1;

		by = ((y + r) * 6 / height) & 1;

		for (x = -xx; x<xx;x++)
		{
			bx = ((x + xx) * 6 / width) & 1;

			retroPixel( screen, x + rx, y + ry, (bx + by) & 1 ? color : 3 );
		}
	}
}


void retroBoing(
       struct retroScreen * screen,
       int x,
       int y,
       int r0,
       int r1,
       unsigned char color0,
       unsigned char color1)
{
	retroBoingOutline( screen,  x,  y,  r1, r1-r0-1, color0 );
	retroBoing( screen, x, y, r0, color0 );
}

