/* :ts=4
 *  $VER: retroFreeSpriteObjects.c $Revision$ (11-Nov-2017)
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

/****** retromode/main/retroFreeSpriteObjects ******************************************
*
*   NAME
*      retroFreeSpriteObjects -- Description
*
*   SYNOPSIS
*      void retroFreeSpriteObjects(struct retroVideo * video);
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

void retroFreeSpriteObject(
       struct retroSpriteObject * spriteObject, BOOL onlyData);

void retroFreeSpriteObjects(
       struct retroVideo * video)
{

	struct retroSpriteObject *spriteObject;

	if (video -> sprites)
	{
		for (spriteObject = video -> sprites; spriteObject < video -> sprites_end; spriteObject++)
		{
			retroFreeSpriteObject(spriteObject, TRUE);
		}

		sys_free(video -> sprites);
		video -> sprites = NULL;
		video -> sprites_end = NULL;
		video -> spriteObjectsAllocated = 0;
	}
}

