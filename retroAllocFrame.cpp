/* :ts=4
 *  $VER: retroAllocFrame.c $Revision$ (19-Oct-2017)
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

/****** retromode/main/retroAllocFrame ******************************************
*
*   NAME
*      retroAllocFrame -- Description
*
*   SYNOPSIS
*      struct retroFrame * retroAllocFrame(struct retroScreen * screen, 
*          int x1, int y1, int x2, int y2, int hotspotX, int hotspotY);
*
*   FUNCTION
*
*   INPUTS
*       screen - 
*       x1 - 
*       y1 - 
*       x2 - 
*       y2 - 
*       hotspotX - 
*       hotspotY - 
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

struct retroFrame * retroAllocFrame(
       struct retroScreen * screen,
       int x1,
       int y1,
       int x2,
       int y2,
       int hotspotX,
       int hotspotY)
{	
	struct retroFrame	*ret = NULL;

	ret = (struct retroFrame *)  sys_alloc_clear( sizeof(struct retroFrame));

	if (ret)
	{
		ret->screen = screen;
		ret->x1 = x1;
		ret->y1 = y1;
		ret->x2 = x2;
		ret->y2 = y2;
		ret->hotspotX = hotspotX;
		ret->hotspotY = hotspotY;
	}

	return ret;

}

