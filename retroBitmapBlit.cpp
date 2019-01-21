/* :ts=4
 *  $VER: retroBitmapBlit.c $Revision$ (19-Oct-2017)
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

#include <stdint.h>
#include <unistd.h>
#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <retromode.h>
#include <retromode_lib.h>
#include <stdarg.h>
#include <math.h>

/****** retromode/main/retroBitmapBlit ******************************************
*
*   NAME
*      retroBitmapBlit -- Description
*
*   SYNOPSIS
*      void retroBitmapBlit(struct BitMap * bitmap, int fromX, int fromY, 
*          int realWidth, int heigh, struct retroScreen * screen, int toX, 
*          int toY);
*
*   FUNCTION
*
*   INPUTS
*       bitmap - 
*       fromX - 
*       fromY - 
*       realWidth - 
*       heigh - 
*       screen - 
*       toX - 
*       toY - 
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

void retroBitmapBlit(
       struct BitMap * bitmap,
       int fromX,
       int fromY,
       int width,
       int height,
       struct retroScreen * screen,
       int toX,
       int toY)
{
	int x,y;
	APTR lock;
	unsigned char *BitMapMemory;
	uint32_t	BitMapBytesPerRow;
	uint32_t	BitMapWidth;
	uint32_t	BitMapHeight;
	unsigned char	*src_memory;
	unsigned char	*des_memory;

	unsigned char	*inner_src_memory;
	unsigned char	*inner_des_memory;


#if 0

	BitMapWidth = libBase -> IGraphics ->GetBitMapAttr( bitmap, BMA_ACTUALWIDTH );
	BitMapHeight = libBase -> IGraphics ->GetBitMapAttr( bitmap, BMA_HEIGHT );

	lock = libBase -> IGraphics -> LockBitMapTags( bitmap, 
			LBM_BytesPerRow, &BitMapBytesPerRow,
			LBM_BaseAddress, &BitMapMemory,
			TAG_END);

	if (lock)
	{
		// handel negative clipping I think.

		if (fromX<0)	{ toX-=fromX; width+=fromX; fromX = 0;}		// - & - is +
		if (fromY<0)	{ toY-=fromY; height+=fromY; fromY = 0;}		// - & - is +

		if (toX<0)	{ fromX-=toX; width+=toX; toX = 0; }		// - & - is +
		if (toY<0)	{ fromY-=toY; height+=toY; toY = 0; }		// - & - is +

		// make sure realWidth is inside source, and destination

		if (fromX+width>BitMapWidth) width = BitMapWidth - fromX;
		if (toX+width>screen->realWidth) width = screen->realWidth - toX;

		// make sure realHeight is inside source, and destination

		if (fromY+height>BitMapHeight) height = BitMapHeight - fromY;
		if (toY+height>screen->realHeight) height = screen->realHeight - toY;

		// we now know the limit, we can now do job, safely.

		src_memory = BitMapMemory + (BitMapBytesPerRow * fromY) + fromX;
		des_memory = screen -> Memory[ screen -> double_buffer_draw_frame ] + (screen -> realWidth * toY) + toX;

		for(y=0;y<height;y++)
		{
			inner_src_memory = src_memory;
			inner_des_memory = des_memory;

			for(x=0;x<width;x++)
			{
				*inner_des_memory++ = *inner_src_memory++;
			}

			src_memory += BitMapBytesPerRow;
			des_memory += screen -> realWidth;
		}
		libBase -> IGraphics -> UnlockBitMap( lock );
	}
#endif
}

