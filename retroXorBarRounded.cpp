/* :ts=4
 *  $VER: retroXorBarRounded.c $Revision$ (04-Nov-2017)
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

#include <stdlib.h>
#include <stdio.h>
#include <exec/exec.h>
#include <proto/exec.h>
#include <dos/dos.h>
#include <exec/types.h>
#include <libraries/retromode.h>
#include <proto/retromode.h>
#include <stdarg.h>
#include <math.h>

/****** retromode/main/retroXorBarRounded ******************************************
*
*   NAME
*      retroXorBarRounded -- Description
*
*   SYNOPSIS
*      void retroXorBarRounded(struct retroScreen * screen, int x0, int y0, 
*          int x1, int y1, int r, unsigned char color);
*
*   FUNCTION
*
*   INPUTS
*       screen - 
*       x0 - 
*       y0 - 
*       x1 - 
*       y1 - 
*       r - 
*       color - 
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

extern void _retromode_retroXorBAR(struct RetroModeIFace *Self, struct retroScreen * screen, int x0, int y0, int x1,int y1,unsigned char color);

void Xorhline( struct retroScreen * screen, int x0, int x1, int y, char color )
{
	unsigned char *from;
	unsigned char *to;
	unsigned char *ptr;

	// exit if out of height

	if (y<0) return;
	if (y>screen->realHeight-1) return;

	// limit x0 and x1

	if (x0<0) x0 = 0;
	if (x1>screen->realWidth-1) x1 = screen->realWidth -1;

	from = screen -> Memory[ screen -> double_buffer_draw_frame ] + ( screen -> realWidth * y ) + x0;
	to = from + (x1-x0) ;

	for(ptr=from;ptr<=to;ptr++)
	{
		*ptr ^= color;
	}
}


void _retromode_retroXorBarRounded(struct RetroModeIFace *Self,
       struct retroScreen * screen,
       int x0,
       int y0,
       int x1,
       int y1,
       int r,
       unsigned char color)
{
	int x, y, r2;
	if (x1-x0<r*2) return;
	if (y1-y0<r*2) return;

	_retromode_retroXorBAR(Self, screen,  x0+r,  y0,  x1-r,  y0+r, color);
	_retromode_retroXorBAR(Self, screen,  x0,  y0 + r +1, x1, y1 - r -1, color);
	_retromode_retroXorBAR(Self, screen,  x0 + r,  y1-r , x1-r, y1 , color);

	r2 = r * r;

	for (y=0;y<r;y++)
	{
		x = sqrt( r2 - (y*y));
		if (x>r) x=r;

		Xorhline( screen, x0+r-x, x0+r-1, y0+r-y, color );
		Xorhline( screen, x1-r+1, x1-r+x, y0+r-y, color );

		Xorhline( screen, x0+r-x, x0+r-1, y1-r+y, color );
		Xorhline( screen, x1-r+1, x1-r+x, y1-r+y, color );
	}
}

