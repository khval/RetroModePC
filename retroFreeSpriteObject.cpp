/* :ts=4
 *  $VER: retroFreeSpriteObject.c $Revision$ (01-Jul-2018)
 *
 *  This file is part of retromode.
 *
 *  Copyright (c) 2018 LiveForIt Software.
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

/****** retromode/main/retroFreeSpriteObject ******************************************
*
*   NAME
*      retroFreeSpriteObject -- Description
*
*   SYNOPSIS
*      void retroFreeSpriteObject(struct retroSpriteObject * spriteObject, 
*          bool onlyData);
*
*   FUNCTION
*
*   INPUTS
*       spriteObject - 
*       onlyData - 
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
       struct retroSpriteObject * spriteObject,
       BOOL onlyData)
{

	int n;

	if (spriteObject)
	{
		for (n=0;n<=1;n++)
		{
			if (spriteObject -> clear[n].mem)
			{
				sys_free(spriteObject -> clear[n].mem);
				spriteObject -> clear[n].mem = NULL;
			}
		}

		if (onlyData==FALSE)
		{
			sys_free(spriteObject);
		}
	}
}

