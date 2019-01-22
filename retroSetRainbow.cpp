/* :ts=4
 *  $VER: retroSetRainbow.c $Revision$ (07-Nov-2017)
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

/****** retromode/main/retroSetRainbow ******************************************
*
*   NAME
*      retroSetRainbow -- Description
*
*   SYNOPSIS
*      struct retroScreen * retroSetRainbow(struct retroVideo * video, 
*          int rainbowNumber, unsigned char color, int tableSize);
*
*   FUNCTION
*
*   INPUTS
*       video - 
*       rainbowNumber - 
*       color - 
*       tableSize - 
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

void retroSetRainbow(
       struct retroVideo * video,
       int rainbowNumber,
       unsigned char color,
       int tableSize)
{

	if (video -> rainbow[rainbowNumber].table) sys_free(video -> rainbow[rainbowNumber].table);

	video -> rainbow[rainbowNumber].color = color;
	video -> rainbow[rainbowNumber].tableSize = tableSize;
	video -> rainbow[rainbowNumber].table = (struct retroRGB *) sys_alloc_clear(sizeof(struct retroRGB)  * video -> rainbow[0].tableSize );
}

