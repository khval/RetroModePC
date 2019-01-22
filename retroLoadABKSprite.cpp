/* :ts=4
 *  $VER: retroLoadABKSprite.c $Revision$ (02-Nov-2017)
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
#include <string.h>


/****** retromode/main/retroLoadABKSprite ******************************************
*
*   NAME
*      retroLoadABKSprite -- Description
*
*   SYNOPSIS
*      struct retroSprite * retroLoadABKSprite(char * filename);
*
*   FUNCTION
*
*   INPUTS
*       filename - 
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


struct retroSprite *read_icon_or_sprite( FILE *fd )
{
	int n;
	int num;
	int bit;
	int Plane;
	unsigned char *byte;
	unsigned char convert[ (255<<3)+8];
	unsigned int sizeOfPlanar,sizeOfChunky;
	char *planar;
	struct retroSprite *sprite;
	short ECSColor;


	sprite = (struct retroSprite *) sys_alloc_clear( sizeof(struct retroSprite) );

	if (!sprite) return NULL;

	if ( fread( &sprite->number_of_frames,sizeof(sprite->number_of_frames), 1, fd ) == sizeof(sprite->number_of_frames) )
	{
		sprite->frames = (struct retroFrameHeader *) sys_alloc_clear( sizeof(struct retroFrameHeader) * sprite->number_of_frames );
	}

	for (n=0; n<sprite->number_of_frames; n++ )
	{

		if (fread( sprite->frames + n, sizeof(struct retroFrameHeaderShort), 1, fd ) == sizeof(struct retroFrameHeaderShort))
		{
			sprite->frames[n].bytesPerRow = sprite->frames[n].PlanarXSize * 16 ;
			sizeOfPlanar = sprite->frames[n].Height * (sprite->frames[n].PlanarXSize * 2 );
			sizeOfChunky = sprite->frames[n].bytesPerRow  * sprite->frames[n].Height;
	
			sprite->frames[n].data = (char *) sys_alloc_clear(  sizeOfChunky );
		}
		else
		{
			sizeOfPlanar = 0;
			sizeOfChunky = 0;
		}

		if (sizeOfPlanar>0)
		{
			planar = (char *) sys_alloc_clear( sizeOfPlanar );
			if (planar)
			{
				// reset convertion table
				for (num=0;num<256;num++)
				{
					for (bit = 0; bit<8; bit++) 
					{
						convert[ (num<<3) | (7-bit) ] = (num & (1 << bit)) ? 1 : 0;
					}
				}

				for (Plane = 0; Plane < sprite->frames[n].NumberOfPlanes; Plane++ )	
				{
					if (fread( planar, sizeOfPlanar, 1, fd ) == sizeOfPlanar) 
					{
						int y;
						int source_BytesPerRow = sprite->frames[n].PlanarXSize*2;
						char *source = planar;
						char *source_ptr = planar;
						char *source_end = planar + source_BytesPerRow;
						long long int *dest_ptr64;	 // 8bits = 8 pixels, 8 pixels is 8 bytes = 64bit :-)

						for (y=0; y<sprite->frames[n].Height;y++)
						{
							dest_ptr64 = (long long int *) (sprite->frames[n].data + (sprite->frames[n].bytesPerRow * y));

							// we can unroll it 16 bit alligned remeber ;-)
							for (source_ptr = source; source_ptr < source_end;  source_ptr++)
							{
								*dest_ptr64++ |= *((long long int *) ( (char *) convert + ((*source_ptr)<<3)));
							}

							source += source_BytesPerRow;
							source_end += source_BytesPerRow;
						}
					}

					// next plane
					for (byte = convert; byte < convert + ((255<<3)+8); byte++ )
					{ 
						*byte = *byte << 1;
					}
				} // Next

				if (planar) 
				{
					sys_free(planar);
					planar = NULL;
				}
			}
		}

		if (sizeOfPlanar == 0) break;
	} // Next


	// in doc it says 32 colors, but we are flexible.

	num = 0;
	while ( fread( &ECSColor, 2, 1, fd ) == 2)	
	{
		ECSColorToRGB32( ECSColor, sprite -> palette[num] );
		num++;
		if (num==256) break;
	}

	return sprite;
}

struct retroSprite * retroLoadABKSprite(
       char * filename)
{

	struct retroSprite *sprite = NULL;
	FILE *fd;
	char file_id[5]; // 4 bytes (0 to 3) byte 5 (4)

	fd = fopen( (char *) filename,"r");

	if (fd)
	{
		file_id[4]= 0;

		if ( fread( file_id, 4, 1, fd ))	// reads 4 bytes but terminates on byte 5.
		{
			if ((strcmp(file_id,"AmSp")==0) || (strcmp(file_id,"AmIc")==0))
			{
				sprite = read_icon_or_sprite( fd );
			}
			else
			{
				printf("[%s]\n",file_id);
			}
		}

		fclose(fd);
	}

	return sprite;
}

