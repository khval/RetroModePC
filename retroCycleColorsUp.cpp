/* :ts=4
 *  $VER: retroCycleColorsUp.c $Revision$ (21-Oct-2017)
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

/****** retromode/main/retroCycleColorsUp ******************************************
*
*   NAME
*      retroCycleColorsUp -- Description
*
*   SYNOPSIS
*      void retroCycleColorsUp(struct retroScreen * screen, 
*          unsigned char from_color, unsigned char to_color, 
*          unsigned char flags);
*
*   FUNCTION
*
*   INPUTS
*       screen - 
*       delay
*       from_color - 
*       to_color - 
*       flags - 
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

void retroCycleColorsUp(
	struct retroScreen * screen,
	unsigned int delay,
	unsigned char from_color,
	unsigned char to_color,
	unsigned char flags)
{
	struct retroShiftColors *new_ShiftColors = NULL;

	int idx = 0;
	int idx_free = -1;

	// look for existing
	for (idx = 0; idx<256; idx++)
	{
		if (screen->allocatedShifts[idx] != NULL)
		{
			if (screen->allocatedShifts[idx] -> firstColor == from_color)
			{
				idx_free = idx;
				new_ShiftColors = screen->allocatedShifts[idx];
				break;
			}
		}
	}

	// add to end if new
	if ((screen -> shiftsAllocated<256)&&(idx_free == -1)) idx_free = screen -> shiftsAllocated;

	if (idx_free>-1)
	{
		if (!new_ShiftColors) new_ShiftColors = (struct retroShiftColors *) sys_alloc_clear( sizeof(struct retroShiftColors) );

		if (new_ShiftColors)
		{
			new_ShiftColors-> delay = delay;
			new_ShiftColors-> firstColor = from_color;
			new_ShiftColors-> lastColor = to_color;
			new_ShiftColors-> flags = (flags&1);

			screen -> shiftsAllocated ++;
			screen -> allocatedShifts[idx_free] = new_ShiftColors;
			screen -> allocatedShifts_end = screen -> allocatedShifts + screen -> shiftsAllocated;
		}
	}
}

