/* :ts=4
 *  $VER: retroSetVideoColor.c $Revision$ (16-Oct-2017)
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

/****** retromode/main/retroSetVideoColor ******************************************
*
*   NAME
*      retroSetVideoColor -- Description
*
*   SYNOPSIS
*      void retroSetVideoColor(struct retroVideo * video, 
*          struct retroRGB * RGB, int color, int from, int to);
*
*   FUNCTION
*
*   INPUTS
*       video - 
*       RGB - 
*       color - 
*       from - 
*       to - 
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

void retroSetVideoColor(
       struct retroVideo * video,
       struct retroRGB * RGB,
       int color,
       int from,
       int to)
{
	int beamY;

	for (beamY = from; beamY< to; beamY++)
	{
		video -> scanlines[beamY].rowPalette[color] = *RGB;
	}
}

