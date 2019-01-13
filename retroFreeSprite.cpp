
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <math.h>

#include "retromode.h"
#include "retromode_lib.h"

/****** retromode/main/retroFreeSprite ******************************************
*
*   NAME
*      retroFreeSprite -- Description
*
*   SYNOPSIS
*      void retroFreeSprite(struct retroSprite * sprite);
*
*   FUNCTION
*
*   INPUTS
*       sprite - 
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

void retroFreeSprite( struct retroSprite * sprite)
{

	if (sprite)
	{
		if (sprite->frames)
		{
			int n;

			for (n=0; n<sprite->number_of_frames; n++ )
			{
				if (sprite->frames[n].data)
				{
					free(sprite->frames[n].data);
					sprite->frames[n].data = NULL;
				}
			 }

			free(sprite->frames);
		}
		free(sprite);
	}
}

