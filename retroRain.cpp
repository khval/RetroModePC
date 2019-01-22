/* :ts=4
 *  $VER: retroRain.c $Revision$ (06-Nov-2017)
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

/****** retromode/main/retroRain ******************************************
*
*   NAME
*      retroRain -- Description
*
*   SYNOPSIS
*      void retroRain(struct retroVideo * video, int rainbowNumber, 
*          int line, int r, int g, int b);
*
*   FUNCTION
*
*   INPUTS
*       video - 
*       rainbowNumber - 
*       line - 
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

void retroRain(
       struct retroVideo * video,
       int rainbowNumber,
       int line,
       int r,
       int g,
       int b)
{
	struct retroRGB *rgb;

	if (line < 0) return;
	if (line > video -> rainbow[rainbowNumber].tableSize-1) return;

	rgb = video -> rainbow[rainbowNumber].table + line;

	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
}

