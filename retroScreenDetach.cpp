/* :ts=4
 *  $VER: retroScreenDetach.c $Revision$ (24-Oct-2017)
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

/****** retromode/main/retroScreenDetach ******************************************
*
*   NAME
*      retroScreenDetach -- Description
*
*   SYNOPSIS
*      void retroScreenDetach(struct retroScreen * screen);
*
*   FUNCTION
*
*   INPUTS
*       screen - 
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

void retroScreenDetach( struct retroScreen * screen)
{
	struct retroVideo * video = screen -> attachedToVideo;
	int found = -1;
	int n;

	if (video)
	{
		if (video -> screensAttached>0)
		{
			video -> refreshAllScanlines = TRUE;
			screen-> attachedToVideo = NULL;	// unattached

			found = -1;
			for (n=0;n<video -> screensAttached;n++)
			{
				if ( video -> attachedScreens[n] == screen )
				{				
					found = n;
					break;
				}
			}

			if (found>-1)	// move table to the left, remove the hole in the table
			{
				for (n=found+1; n < video -> screensAttached;n++)
				{
					video -> attachedScreens[n-1] = video -> attachedScreens[n];
				}
			}

			video -> screensAttached --;
			video -> attachedScreens_end = video -> attachedScreens + video -> screensAttached;
		}
	}

}

