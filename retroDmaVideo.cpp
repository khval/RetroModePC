/* :ts=4
 *  $VER: retroDmaVideo.c $Revision$ (16-Oct-2017)
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

/****** retromode/main/retroDmaVideo ******************************************
*
*   NAME
*      retroDmaVideo -- Description
*
*   SYNOPSIS
*      void retroDmaVideo(struct retroVideo * video);
*
*   FUNCTION
*
*   INPUTS
*       video - 
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

void retroDmaVideo(
       struct retroVideo * video)
{

#if 0
	// move gfx from system mem to video mem.

	libBase -> IGraphics -> WritePixelArray( (uint8 * ) video->Memory, 0, 0, video->BytesPerRow, PIXF_A8R8G8B8, 
			&video->rp, 0,0, video->width,video->height);
#endif

}

