/* :ts=4
 *  $VER: retroOpenScreen.c $Revision$ (03-Oct-2017)
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

/****** retromode/main/retroOpenScreen ******************************************
*
*   NAME
*      retroOpenScreen -- Description
*
*   SYNOPSIS
*      struct retroScreen * retroOpenScreen(int width, int height, int videomode);
*
*   FUNCTION
*
*   INPUTS
*       width - 
*       height - 
*       videomode - 
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

void retroCloseScreen( struct retroScreen **screen);

struct retroScreen * retroOpenScreen(
      	int width,
	int height,
	int videomode)
{

	struct retroScreen *screen;

	screen = (struct retroScreen *) sys_alloc_clear( sizeof(struct retroScreen) );

	if (screen)
	{
		screen -> clones = 0;
		screen -> cloneOfScreen = NULL;
		screen -> realWidth = width;
		screen -> realHeight = height;
		screen -> videomode = videomode;
		screen -> autoback = 2;
		screen -> fade_speed = 0;
		screen -> fade_count = 0;
		screen -> currentTextWindow = NULL;
		screen -> textWindows = NULL;
		screen -> allocatedTextWindows = 0;
		screen -> double_buffer_draw_frame = 0;

		screen -> Memory[0] = (unsigned char *) sys_alloc_clear( screen -> bytesPerRow * (screen -> realHeight+1) );

		screen -> Memory[1] = NULL;

		// if fail
		if (screen -> Memory[0] == NULL)
		{
			retroCloseScreen( &screen );
			return NULL;
		}
	}

	return screen;
}

