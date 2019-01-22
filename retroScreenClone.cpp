/* :ts=4
 *  $VER: retroScreenClone.c $Revision$ (06-Nov-2017)
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

/****** retromode/main/retroScreenClone ******************************************
*
*   NAME
*      retroScreenClone -- Description
*
*   SYNOPSIS
*      void retroScreenClone(struct retroScreen * SourceScreen, 
*          int videomode);
*
*   FUNCTION
*
*   INPUTS
*       SourceScreen - 
*       videomode - 
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

struct retroScreen * retroScreenClone(
       struct retroScreen * sourceScreen,
       int videomode)
{

	struct retroScreen *screen;

	if (sourceScreen == NULL) return NULL;

	screen = (struct retroScreen *) sys_alloc_clear( sizeof(struct retroScreen) );
	if (screen)
	{
		sourceScreen -> clones ++;

		screen -> realWidth = sourceScreen -> realWidth;
		screen -> realHeight = sourceScreen -> realHeight;
		screen -> displayWidth = sourceScreen -> displayWidth;
		screen -> displayHeight = sourceScreen -> displayHeight;
		screen -> videomode = videomode;
		screen -> Memory[0] = sourceScreen -> Memory[0];
		screen -> Memory[1] = sourceScreen -> Memory[1];
		screen -> cloneOfScreen = sourceScreen;

		// if fail
		if (screen -> Memory == NULL)
		{
			retroCloseScreen( &screen );
			return NULL;
		}
	}
	return screen;
}

