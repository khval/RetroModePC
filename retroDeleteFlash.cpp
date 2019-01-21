/* :ts=4
 *  $VER: retroDeleteFlash.c $Revision$ (21-Oct-2017)
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

/****** retromode/main/retroDeleteFlash ******************************************
*
*   NAME
*      retroDeleteFlash -- Description
*
*   SYNOPSIS
*      void retroDeleteFlash(struct retroScreen * screen, 
*          unsigned char color);
*
*   FUNCTION
*
*   INPUTS
*       screen - 
*       color - 
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

int retroDeleteFlash(
       struct retroScreen * screen,
       unsigned char color)
{


	int idx = 0;
	struct retroFlashTable *flash = NULL;

	for (idx = 0; idx<256; idx++)
	{
		if (screen->allocatedFlashs[idx] != NULL)
		{
			if (screen->allocatedFlashs[idx] -> color == color)
			{
				flash = screen->allocatedFlashs[idx];

				if (flash -> table)
				{
					sys_free(flash -> table);
					flash -> table = NULL;
				}

				sys_free(screen->allocatedFlashs[idx]);	
				for ( ; idx<255;idx++)
				{
					screen->allocatedFlashs[idx] = screen->allocatedFlashs[idx+1];
				}

				screen->allocatedFlashs[255] = NULL;
				screen->flashsAllocated--;		// flash tables
				screen->allocatedFlashs_end = screen->allocatedFlashs + screen-> flashsAllocated;
				break;
			}
		}
	}

	return -1;
}

