/* :ts=4
 *  $VER: retroCloseScreen.c $Revision$ (03-Oct-2017)
 *
 *  This file is part of retromode.
 *
 *  Copyright (c) 2017 LiveForIt Software.
 *  MIT License
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

/****** retromode/main/retroCloseScreen ******************************************
*
*   NAME
*      retroCloseScreen -- Description
*
*   SYNOPSIS
*      void retroCloseScreen(struct retroScreen * screen);
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

extern void retroScreenDetach( struct retroScreen * screen);

void retroCloseScreen( struct retroScreen **screen)
{
	struct retroFlashTable * flash;
	struct retroShiftColors * shift;
	int idx;

	if (screen == NULL)
	{
		printf("your passing a NULL pointer, you should be passing ref to pointer &screenPointer\n");
		return;
	}

	if (*screen==NULL)
	{
		printf("you have closed this Screen before, maybe your clsong the wrong Screen?\n");
		return;
	}

	if ((*screen) -> clones > 0)
	{
		printf("you are closeing Screen in the wrong order, close clones before original screen?\n");
		return;
	}

	retroScreenDetach( *screen );

	for (idx = 0; idx<256; idx++)
	{
		flash = (*screen)->allocatedFlashs[idx];
		if (flash)
		{
			if (flash -> table)
			{
				sys_free(flash -> table);
				flash -> table = NULL;
			}
			sys_free(flash);
			(*screen)->allocatedFlashs[idx] = NULL;	
		}

		shift = (*screen)->allocatedShifts[idx];
		if (shift)
		{
			sys_free(shift);
			(*screen)->allocatedShifts[idx] = NULL;	
		}
	}
	
	if ((*screen) -> cloneOfScreen)
	{
		(*screen) -> cloneOfScreen -> clones--;	// I guess we might use list, but I'm too lazy
	}
	else
	{
		if ((*screen) -> Memory[0]) sys_free((*screen) -> Memory[0]);
		if ((*screen) -> Memory[1]) sys_free((*screen) -> Memory[1]);
	}

	(*screen) -> Memory[0] = NULL;
	(*screen) -> Memory[1] = NULL;

	sys_free(*screen);
	*screen = NULL;
}

