/* :ts=4
 *  $VER: retroClearVideo.c $Revision$ (16-Oct-2017)
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

/****** retromode/main/retroClearVideo ******************************************
*
*   NAME
*      retroClearVideo -- Description
*
*   SYNOPSIS
*      void retroClearVideo(struct retroVideo * video);
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

void retroClearVideo( struct retroVideo * video)
{
	int size =  video->BytesPerRow * video -> height ;
	unsigned int *mem;

	size /= 4; // get number of ints.
	size /= 4; // unroll 4.

	mem = video -> Memory;

	while (size-- )
	{
		*mem++=0;
		*mem++=0;
		*mem++=0;
		*mem++=0;
	}
}

