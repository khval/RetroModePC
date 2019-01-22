/* :ts=4
 *  $VER: retroPoint.c $Revision$ (11-Oct-2017)
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

/****** retromode/main/retroPoint ******************************************
*
*   NAME
*      retroPoint -- Description
*
*   SYNOPSIS
*      unsigned char retroPoint(struct retroScreen * screen, int x, int y);
*
*   FUNCTION
*
*   INPUTS
*       screen - 
*       x - 
*       y - 
*
*   RESULT
*       The result ...
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

unsigned char retroPoint(  struct retroScreen * screen, int x, int y)
{
	if (x<0) return 0;
	if (y<0) return 0;
	if (x>=screen->realWidth) return 0;
	if (y>=screen->realHeight) return 0;

	 return screen -> Memory[screen -> double_buffer_draw_frame][ screen -> realWidth * y + x ];
}

