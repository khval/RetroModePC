/* :ts=4
 *  $VER: retroCycleOff.c $Revision$ (11-May-2018)
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

/****** retromode/main/retroCycleOff ******************************************
*
*   NAME
*      retroCycleOff -- Description
*
*   SYNOPSIS
*      void retroCycleOff(struct retroScreen * screen);
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

void retroCycleOff( struct retroScreen * screen)
{
	struct retroShiftColors **shift;

	for (shift = screen -> allocatedShifts ; shift < screen -> allocatedShifts_end; shift ++)
	{
		if (*shift) sys_free(*shift);
		*shift = NULL;
	}

	screen -> shiftsAllocated = 0;
	screen -> allocatedShifts_end = screen -> allocatedShifts;
}

