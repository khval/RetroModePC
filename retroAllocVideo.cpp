/* :ts=4
 *  $VER: alloc_retoVideo.c $Revision$ (03-Oct-2017)
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

/****** retromode/main/retroAllocVideo ******************************************
*
*   NAME
*      retroAllocVideo -- Description
*
*   SYNOPSIS
*      struct retroVideo * retroAllocVideo(struct Window * window);
*
*   FUNCTION
*
*   INPUTS
*       window - 
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

void config_scanline( 
		struct retroScanline *scanline,
		int pixels,
		void (*mode) ( struct retroScanline *line, int beamY, unsigned int *video_buffer  ),
		unsigned char *data0,
		unsigned char *data1
	 )
{
	scanline->pixels = pixels;
	scanline->mode = mode;
	scanline->data[0] = data0;
	scanline->data[1] = data1;
}

struct retroVideo * retroAllocVideo()
{
	struct retroVideo *new_video = NULL;
	struct retroRGB RGB000;


	RGB000.r = 0;
	RGB000.g = 0;
	RGB000.b = 0;


	new_video = (struct retroVideo *) sys_alloc_clear( sizeof(struct retroVideo) );

	if (new_video)
	{
		int scanline;
		int c;

		new_video -> refreshAllScanlines = TRUE;
		new_video -> refreshSomeScanlines = FALSE;

		new_video -> width = 640;
		new_video -> height = 480;

		for ( scanline=0; scanline< new_video -> height ;scanline++) config_scanline( &new_video -> scanlines[scanline] , 0, NULL, NULL, NULL );

		for ( c = 0; c<3 ;c++) new_video -> rainbow[c].table = NULL;

#if 0

		libBase -> IGraphics -> InitRastPort(&new_video->rp);
		new_video -> window = window;
		new_video -> rp.BitMap = libBase -> IGraphics -> AllocBitMap( new_video -> width , new_video -> height, 32, BMF_DISPLAYABLE, new_video -> window ->RPort -> BitMap);

		if (new_video -> rp.BitMap )
		{
			// We create a mirror copy in system ram.
			new_video -> BytesPerRow = libBase -> IGraphics -> GetBitMapAttr( new_video -> rp.BitMap, BMA_WIDTH)  * 4;
			new_video -> Memory = (unsigned int *)  sys_alloc_clear( new_video -> BytesPerRow * (new_video -> height  + 1), 
						AVT_Type, MEMF_SHARED, 
						AVT_ClearWithValue, 0 ,
						TAG_END	);
		}


		if (( ! new_video -> Memory) || ( ! new_video -> rp.BitMap ))
		{
			Self -> retroFreeVideo( new_video );
			return NULL;
		}

#else

			new_video -> BytesPerRow = new_video -> width * 4;
			new_video -> Memory = (unsigned int *)  sys_alloc_clear( new_video -> BytesPerRow * (new_video -> height  + 1));
	#endif

	}

	return  new_video;
}

