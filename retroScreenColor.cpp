/* :ts=4
 *  $VER: retroScreenColor.c $Revision$ (03-Oct-2017)
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

/****** retromode/main/retroScreenColor ******************************************
*
*   NAME
*      retroScreenColor -- Description
*
*   SYNOPSIS
*      void retroScreenColor(struct retroScreen * screen, int color, 
*          unsigned char r, unsigned char g, unsigned char b);
*
*   FUNCTION
*
*   INPUTS
*       screen - 
*       color - 
*       r - 
*       g - 
*       b - 
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

void retroScreenColor(
       struct retroScreen * screen,
       int color,
       unsigned char r,
       unsigned char g,
       unsigned char b)
{
	screen -> orgPalette[color].r = r;
	screen -> orgPalette[color].g = g;
	screen -> orgPalette[color].b = b;

	screen -> rowPalette[color].r = r;
	screen -> rowPalette[color].g = g;
	screen -> rowPalette[color].b = b;
}

