/* :ts=4
 *  $VER: AfterEffectScanline.c $Revision$ (11-Oct-2017)
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

/****** retromode/main/AfterEffectScanline ******************************************
*
*   NAME
*      AfterEffectScanline -- Description
*
*   SYNOPSIS
*      void AfterEffectScanline(struct retroVideo * video);
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

void AfterEffectScanline(
       struct retroVideo * video)
{
			int scanline=0;
	int x;
	unsigned int *src_mem = video -> Memory;
	unsigned int *des_ptr;
	unsigned int *src_ptr;
	int intsPerRow = video -> BytesPerRow / 4;


	src_mem += intsPerRow;	// next line

	for ( scanline = 1 ; scanline < video->height ; scanline++ )
	{
		if (video -> scanlines[scanline].data == NULL)
		{
			if ( video -> scanlines[scanline-1].data)	// if pre line has some data.
			{
				src_ptr = src_mem- intsPerRow;
				des_ptr = src_mem ;

				for (x=0;x<video->width;x++)
				{
					*des_ptr++=*src_ptr++;
//					*des_ptr++=(((*src_ptr++) & 0xFCFCFC) >> 1) | 0xFF000000;
				}
			}
		}
		src_mem += intsPerRow;	// next line
	}
}

