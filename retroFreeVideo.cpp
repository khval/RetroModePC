/* :ts=4
 *  $VER: free_retroVideo.c $Revision$ (03-Oct-2017)
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


/****** retromode/main/retroFreeVideo ******************************************
*
*   NAME
*      retroFreeVideo -- Description
*
*   SYNOPSIS
*      void retroFreeVideo(struct retroVideo * video);
*
*   FUNCTION
*
*   INPUTS
*       video - 
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

void retroFreeVideo(
       struct retroVideo * video)
{

	int c;

	Self -> retroFreeSpriteObjects( video );

	if (video->rp.BitMap)
	{
		libBase-> IGraphics->FreeBitMap( video-> rp.BitMap );
		video -> rp.BitMap = NULL;
	}

	for ( c = 0; c<3 ;c++) 
	{
		if (video -> rainbow[c].table)
		{
			libBase -> IExec ->sys_free (video -> rainbow[c].table);
			video -> rainbow[c].table = NULL;
		}
	}

	if (video->Memory)
	{
		libBase -> IExec ->sys_free (video->Memory);
		video->Memory = NULL;
	}

	libBase -> IExec ->sys_free ( (void *) video );
}

