/* :ts=4
 *  $VER: retroAllocDoubleBuffer.c $Revision$ (06-Jun-2018)
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

/****** retromode/main/retroAllocDoubleBuffer ******************************************
*
*   NAME
*      retroAllocDoubleBuffer -- Description
*
*   SYNOPSIS
*      void retroAllocDoubleBuffer(struct retroScreen * screen);
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

void retroAllocDoubleBuffer(  struct retroScreen * screen)
{

	if (screen -> Memory[1] == NULL )
	{ 
		int _size_ = screen -> bytesPerRow * (screen -> realHeight+1);
		unsigned char *src_ptr,*dest_ptr;
		unsigned char *mem_end;

		screen -> Memory[1] = (unsigned char *) sys_alloc_clear(  _size_ );

		src_ptr = screen -> Memory[0];
		dest_ptr=screen -> Memory[1];
		mem_end = screen -> Memory[1] + _size_;

		for(;dest_ptr<mem_end;dest_ptr++)
		{
			*dest_ptr	= *src_ptr; src_ptr++;
		}		
	}
}

