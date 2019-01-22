/* :ts=4
 *  $VER: retroScreenFront.c $Revision$ (24-Oct-2017)
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

/****** retromode/main/retroScreenFront ******************************************
*
*   NAME
*      retroScreenFront -- Description
*
*   SYNOPSIS
*      void retroScreenToFront(struct retroScreen * screen, int offsetx, 
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

void retroScreenToFront( struct retroScreen * screen)
{
	struct retroVideo *video; 
	struct retroScreen **ptr;

	if (!screen -> attachedToVideo) return;

	video = screen -> attachedToVideo;
	for ( ptr = video -> attachedScreens; ptr<video -> attachedScreens_end ; ptr++)
	{
		if ( *ptr == screen)
		{
			for ( ; ptr<video -> attachedScreens_end-1 ; ptr++)
			{
				*ptr = *(ptr+1);
			}
			break;
		}
	}

	if ( video -> screensAttached > 0) *(video -> attachedScreens_end -1) = screen;
}

