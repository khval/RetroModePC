/* :ts=4
 *  $VER: retroGetSprite.c $Revision$ (30-Jun-2018)
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
#include <string.h>

/****** retromode/main/retroGetSprite ******************************************
*
*   NAME
*      retroGetSprite -- Description
*
*   SYNOPSIS
*      void retroGetSprite(struct retroScreen * screen, 
*          struct retroSprite * sprite, int image, int x0, int y0, int x1, 
*          int y1);
*
*   FUNCTION
*
*   INPUTS
*       screen - 
*       sprite - 
*       image - 
*       x0 - 
*       y0 - 
*       x1 - 
*       y1 - 
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


struct retroFrame * retroAllocFrame(
       struct retroScreen * screen, int x1, int y1, int x2, int y2, int hotspotX, int hotspotY);

void retroGetSprite(
       struct retroScreen * screen,
       struct retroSprite * sprite,
       int image,
       int x0,
       int y0,
       int x1,
       int y1)
{

	struct retroFrameHeader *frame;
	int ypos;
	int destination_x0 = 0,destination_y0 = 0;
	unsigned char *source_row_ptr;
	unsigned char *source_row_start;
	unsigned char *destination_row_start;
	unsigned char *destination_row_ptr;
	unsigned char *destination_row_end ;
	unsigned int sizeOfChunky;

	if (image < 0) image = 0;

	if (image >= sprite -> number_of_frames)
	{
		int n;
		struct retroFrameHeader *new_frames;
		int old_frames = sprite->number_of_frames;
		int new_frames_count  = image+1;

		new_frames = (struct retroFrameHeader *) sys_alloc_clear( sizeof(struct retroFrameHeader) *  new_frames_count );

		if (new_frames)
		{
			memcpy( new_frames, sprite -> frames, sizeof(struct retroFrameHeader) *  old_frames );
			sys_free( sprite -> frames );
			sprite -> frames = new_frames;
			sprite -> number_of_frames = new_frames_count;
		}
	}

	frame = sprite -> frames + image;

	frame -> XHotSpot = 0;
	frame -> YHotSpot = 0;	
	frame -> Width  = x1-x0+1;
	frame -> Height = y1-y0+1;
	frame -> bytesPerRow  = frame -> Width;

	sizeOfChunky = frame -> bytesPerRow  * frame -> Height;
	if ( frame -> data ) sys_free( (void *) frame -> data );
	frame -> data = (char *) sys_alloc_clear( sizeOfChunky );

	{
		int width = frame -> Width;
		int height = frame -> Height;

		if (y0+height>screen->realHeight) height = screen->realHeight - y0;
		if (x0+width>screen->realWidth) width = screen->realWidth - x0;

		if (y0<0) { destination_y0 = -y0; y0 = 0; height -= destination_y0;  }
		if (x0<0) { destination_x0 = -x0; x0 = 0; width -= destination_x0; }

		source_row_start = screen -> Memory[ screen -> double_buffer_draw_frame ] + (screen -> realWidth * y0) + x0;

		if (frame -> data)
		{
			destination_row_start = (unsigned char *) frame -> data + (destination_y0 * frame -> bytesPerRow );
			destination_row_end = destination_row_start + width;

			for ( ypos = 0; ypos < height; ypos++ )
			{
				source_row_ptr = source_row_start;

				for ( destination_row_ptr = destination_row_start;  destination_row_ptr < destination_row_end ; destination_row_ptr++ )
				{
					*destination_row_ptr= *source_row_ptr;
					source_row_ptr++;
				}

				source_row_start += screen -> realWidth;
				destination_row_start += frame -> bytesPerRow;
				destination_row_end += frame -> bytesPerRow;
			}
		}
	}
}

