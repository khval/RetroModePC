/* :ts=4
 *  $VER: retroPixel.c $Revision$ (11-Oct-2017)
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

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <retromode.h>
#include <retromode_lib.h>
#include <stdarg.h>
#include <math.h>

/****** retromode/main/retroPixel ******************************************
*
*   NAME
*      retroPixel -- Description
*
*   SYNOPSIS
*      void retroPixel(struct retroScreen * screen, int x, int y, 
*          unsigned char color);
*
*   FUNCTION
*
*   INPUTS
*       screen - 
*       x - 
*       y - 
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

void retroPixel( struct retroScreen * screen, int x, int y, unsigned char color)
{
	if (x<0) return;
	if (y<0) return;
	if (x>=screen->realWidth) return;
	if (y>=screen->realHeight) return;

	screen -> Memory[screen -> double_buffer_draw_frame][ screen -> realWidth * y + x ] = color;
}

