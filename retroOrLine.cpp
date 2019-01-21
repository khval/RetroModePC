/* :ts=4
 *  $VER: retroBAR.c $Revision$ (03-Oct-2017)
 *
 *  This file is part of retromode.
 *
 *  Copyright (c) 2017 LiveForIt Software.
 *  MIT License
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

/****** retromode/main/retroOrLine ******************************************
*
*   NAME
*      retroOrLine -- Description
*
*   SYNOPSIS
*      void retroOrLine(struct retroScreen * screen, int x1, int y1, int x2, 
*          int y2, unsigned char color);
*
*   FUNCTION
*
*   INPUTS
*       screen - 
*       x1 - 
*       y1 - 
*       x2 - 
*       y2 - 
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

void _retromode_retroOrLine(struct RetroModeIFace *Self,
       struct retroScreen * screen,
       int x1,
       int y1,
       int x2,
       int y2,
       unsigned char color)
{
	unsigned char *memory;
	double dx,dy;
	double a;
	double y,_y2;
	int bytesPerRow = screen -> realWidth;
	int height = screen -> realHeight;
	int _x;
	double _y;
	int dirx;
	int sdx;	// signed delta x

	if (x2>x1)
	{
		dx = (double) x2 - (double) x1 + 1.0f;
		dy = (double) y2 - (double) y1 ;
		sdx = dx;
		dirx = 1;
	}
	else
	{
		dx = (double) x1 - (double) x2 + 1.0f;
		dy = (double) y2 - (double) y1 ;
		sdx = - dx;
		dirx = -1;
	}

	a = (dx == 0) ? 0 : dy / dx;

	if (x1+sdx<0) dx = x1;
	if (x1+sdx>screen->realWidth-1) dx=screen->realWidth-x1-1;

	memory = screen -> Memory[ screen -> double_buffer_draw_frame ] +  x1;

	y = (double) y1;

	if (y1>y2)
	{
		for (_x=0;_x<dx;_x++)
		{
			_y2 = y + a;

			for (_y = y; _y>_y2;_y--)
				if ((_y>0)&&(_y<height)) memory[ bytesPerRow * (int) _y ] = color;

			memory+=dirx;
			y+=a;
		}
	}
	else
	{
		for (_x=0;_x<dx;_x++)
		{
			_y2 = y + a;

			for (_y = y; _y<_y2;_y++)
				if ((_y>0)&&(_y<height)) memory[ bytesPerRow * (int) _y ] |= color;

			memory+=dirx;
			y+=a;
		}
	}
}

