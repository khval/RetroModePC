/* :ts=4
 *  $VER: retroOrScreenBlit.c $Revision$ (19-Oct-2017)
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

#include <stdlib.h>
#include <stdio.h>
#include <exec/exec.h>
#include <proto/exec.h>
#include <dos/dos.h>
#include <exec/types.h>
#include <libraries/retromode.h>
#include <proto/retromode.h>
#include <stdarg.h>
#include <libbase.h>

/****** retromode/main/retroOrScreenBlit ******************************************
*
*   NAME
*      retroOrScreenBlit -- Description
*
*   SYNOPSIS
*      void retroOrScreenBlit(struct BitMap * bitmap, int fromX, int fromY, 
*          int realWidth, int heigh, struct retroScreen * screen, int toX, 
*          int toY);
*
*   FUNCTION
*
*   INPUTS
*       bitmap - 
*       fromMode - logical or physical screen
*       fromX - 
*       fromY - 
*       realWidth - 
*       heigh - 
*       screen - 
*       toMode - logical or physical screen
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

void _retromode_retroOrScreenBlit(struct RetroModeIFace *Self,
	struct retroScreen *source,
	int formMode,
	int fromX,
	int fromY,
	int width,
	int height,
	struct retroScreen *destination,
	int toMode,
	int toX,
	int toY)
{
//	struct RetroLibrary *libBase = (struct RetroLibrary *) Self -> Data.LibBase;
	// pointers
	unsigned char *destination_horizontal_ptr;

	// range
	unsigned char *src_vertical_ptr;
	unsigned char *src_vertical_end;
	unsigned char *src_horizontal_ptr;
	unsigned char *src_horizontal_end;
	unsigned char *destination_memory;
	unsigned char *destination_end;
	unsigned int source_double_buffer_draw_frame,destination_double_buffer_draw_frame;

	switch (formMode)
	{
		case 1:	// physical
				source_double_buffer_draw_frame = (source ->Memory[1]) ? 1-source -> double_buffer_draw_frame : source -> double_buffer_draw_frame;
				break;

		default:	// Logical
				source_double_buffer_draw_frame = source -> double_buffer_draw_frame;
				break;
	}

	switch (toMode)
	{
		case 1:	 // physical
				destination_double_buffer_draw_frame = (destination ->Memory[1]) ? 1-destination -> double_buffer_draw_frame : destination -> double_buffer_draw_frame;
				break;

		default:	// Logical
				destination_double_buffer_draw_frame = destination -> double_buffer_draw_frame;
				break;
	}

	destination_end = destination -> Memory[destination_double_buffer_draw_frame] + ( destination->realHeight * destination->realHeight );

	// limit to 0,0

	if (fromX<0)	{ toX-=fromX; width+=fromX; fromX = 0;}		// - & - is +
	if (fromY<0)	{ toY-=fromY; height+=fromY; fromY = 0;}		// - & - is +

	if (toX<0)	{ fromX-=toX; width+=toX; toX = 0; }		// - & - is +
	if (toY<0)	{ fromY-=toY; height+=toY; toY = 0; }		// - & - is +

	// make sure realWidth is inside source, and destination

	if (fromX+width>source->realWidth) width = source->realWidth - fromX;
	if (toX+width>destination->realWidth) width = destination->realWidth - toX;

	// make sure realHeight is inside source, and destination

	if (fromY+height>source->realHeight) height = source->realHeight - fromY;
	if (toY+height>destination->realHeight) height = destination->realHeight - toY;

	// we now know the limit, we can now do the job, safely.

	src_vertical_ptr = source -> Memory[source_double_buffer_draw_frame] + (source -> bytesPerRow * fromY) + fromX;
	src_vertical_end = src_vertical_ptr + (height * source -> bytesPerRow);

	destination_memory = destination -> Memory[destination_double_buffer_draw_frame] + (destination -> realWidth * toY) + toX;

	for(;src_vertical_ptr<src_vertical_end;src_vertical_ptr += source -> realWidth)
	{
		destination_horizontal_ptr = destination_memory;
		src_horizontal_end =src_vertical_ptr+width;

		for(src_horizontal_ptr=src_vertical_ptr;src_horizontal_ptr<src_horizontal_end;src_horizontal_ptr++)
		{
			*destination_horizontal_ptr++ |= *src_horizontal_ptr;
		}
		destination_memory += destination -> realWidth;
	}
}

