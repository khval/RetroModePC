
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <byteswap.h>

#include "config.h"
#include "retromode.h"
#include "retromode_lib.h"


/****** retromode/main/retroLoadSprite ******************************************
*
*   NAME
*      retroLoadSprite -- Description
*
*   SYNOPSIS
*      struct retroSprite * retroLoadSprite(void * fd);
*
*   FUNCTION
*
*   INPUTS
*       fd - 
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


struct retroSprite * retroLoadSprite( void *fd, cust_fread_t cust_fread)
{
#ifdef __amigaos4__

#endif
	int n;
	int num;
	int bit;
	int Plane;
	unsigned char *byte;
	unsigned char convert[ (256<<3)+8];	// 0 to 255 is 256 numbers.
	unsigned int sizeOfPlanar,sizeOfChunky;
	char *planar;
	struct retroSprite *sprite;
	short ECSColor;
	int colors = 0;


	sprite = (struct retroSprite *) sys_alloc_clear(  sizeof(struct retroSprite) );

	if (!sprite) return NULL;

	sprite->frames = NULL;			// set default value
	sprite->number_of_frames=0;

	if ( cust_fread( &sprite->number_of_frames,sizeof(sprite->number_of_frames), 1, fd ) == 1 )
	{

#if defined(__LITTLE_ENDIAN__)
		sprite->number_of_frames = __bswap_16(sprite->number_of_frames);
#endif

		printf("Load sprite->number_of_frames %d\n",  sprite->number_of_frames);

		sprite->frames = (struct retroFrameHeader *) sys_alloc_clear(sizeof(struct retroFrameHeader) * sprite->number_of_frames);

		if (sprite->frames == NULL) sprite->number_of_frames=0;
	}

	if (sprite->frames)
	{
		for (n=0; n<sprite->number_of_frames; n++ )
		{
			if (cust_fread( sprite->frames + n, sizeof(struct retroFrameHeaderShort), 1, fd ) == 1 )
			{

#if defined(__LITTLE_ENDIAN__)
		sprite->frames[n].PlanarXSize = __bswap_16(sprite->frames[n].PlanarXSize);
		sprite->frames[n].Height = __bswap_16(sprite->frames[n].Height);
#endif

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
						if (cust_fread( planar, sizeOfPlanar, 1, fd ) == 1) 
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

			if (colors<(1L<<sprite->frames[n].NumberOfPlanes)) colors = 1L<<sprite->frames[n].NumberOfPlanes;

		} // Next


		// in doc it says 32 colors, but we are flexible.
		if (colors<32) colors = 32;	

		num = 0;
		while (cust_fread( &ECSColor, 2, 1, fd ) == 1)	
		{
			ECSColorToRGB32( ECSColor, sprite -> palette[num] );
			num++;
			if (num==colors) break;
		}
	}

	return sprite;
}

