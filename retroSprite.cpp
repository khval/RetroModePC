/* :ts=4
 *  $VER: retroSprite.c $Revision$ (12-Nov-2017)
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

/****** retromode/main/retroSprite ******************************************
*
*   NAME
*      retroSprite -- Description
*
*   SYNOPSIS
*      void retroSprite(struct retroVideo * video, int number, int x, int y, 
*          int image);
*
*   FUNCTION
*
*   INPUTS
*       video - 
*       number - 
*       x - 
*       y - 
*       image - 
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

void retroSprite(
       struct retroVideo * video,
       int number,
       int x,
       int y,
       int image)
{
//
//	libBase->IDOS->Printf("video -> sprites[%ld].sprite = %lx\n",number, video -> sprites[number].sprite);

	if (video -> sprites[number].sprite)
	{
		if (video -> sprites[number].sprite->frames)
		{
			video -> sprites[number].frame = video -> sprites[number].sprite->frames +image ;
		}
	}

	video -> sprites[number].x = x;
	video -> sprites[number].y = y;
}

