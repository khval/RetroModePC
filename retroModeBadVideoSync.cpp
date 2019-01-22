/* :ts=4
 *  $VER: retroModeBadVideoSync.c $Revision$ (11-Oct-2017)
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

/****** retromode/main/retroModeBadVideoSync ******************************************
*
*   NAME
*      retroModeBadVideoSync -- Description
*
*   SYNOPSIS
*      void retroModeBadVideoSync(struct retroVideo * video, 
*          double sync_offset, double incRad);
*
*   FUNCTION
*
*   INPUTS
*       video - 
*       sync_offset - 
*       incRad - 
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

void retroModeBadVideoSync(
	struct retroVideo * video,
	double sync_offset,
	double incRad,
	double r)
{
	double a;
	int scanline;

	a = sync_offset;

	for ( scanline = 1 ; scanline < video->height ; scanline++ )
	{
		video -> scanlines[scanline-1].beamStart = sin(a) * r;

		a += incRad;	
	}
}

