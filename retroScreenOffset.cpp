/* :ts=4
 *  $VER: retroScreenOffset.c $Revision$ (24-Oct-2017)
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

/****** retromode/main/retroScreenOffset ******************************************
*
*   NAME
*      retroScreenOffset -- Description
*
*   SYNOPSIS
*      void retroScreenOffset(struct retroScreen * screen, int offsetx, 
*          int offsety);
*
*   FUNCTION
*
*   INPUTS
*       screen - 
*       offsetx - 
*       offsety - 
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

void retroScreenOffset(
       struct retroScreen * screen,
       int offsetx,
       int offsety)
{
	struct retroVideo * video;
	if (offsetx<0) offsetx = 0;
	if (offsety<0) offsety = 0;
	if (offsetx+screen->displayWidth>screen->realWidth) offsetx = screen->realWidth - screen->displayWidth;
	if (offsety+screen->displayHeight>screen->realHeight) offsety = screen->realHeight - screen->displayHeight;

	screen -> offset_x = offsetx;
	screen -> offset_y = offsety;

	video = screen -> attachedToVideo;
	if (video)
	{
		video -> refreshSomeScanlines = TRUE;
		screen -> refreshScanlines = TRUE;
	}
}


