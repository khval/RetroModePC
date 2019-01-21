/* :ts=4
 *  $VER: retroBobble.c $Revision$ (05-Nov-2017)
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

/****** retromode/main/retroBobble ******************************************
*
*   NAME
*      retroBobble -- Description
*
*   SYNOPSIS
*      void retroBobble(struct retroScreen * fromScreen, int fromX, int fromY, 
*          int fromR,struct retroScreen *toScreen,  int toX, int toY, int toR);
*
*   FUNCTION
*
*   INPUTS
*       screen - 
*       fromX - 
*       fromY - 
*       fromR - 
*       screen - 
*       toX - 
*       toY - 
*       toR - 
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


void retroBobble(
       struct retroScreen * fromScreen,
       int fromX,
       int fromY,
       int fromR,
       struct retroScreen * toScreen,
       int toX,
       int toY,
       int toR)
{
	int sourceX, sourceY;
	int destinationX, destinationY;
	char color;
	double r;

	for (destinationY = 0 ; destinationY < toR ; destinationY++)
	{
		sourceY = sin( (M_PI/2.0f) * destinationY / toR ) * fromR;

		for (destinationX = 0 ; destinationX < toR ; destinationX++)
		{
			r = sqrt( (destinationX*destinationX) + (destinationY*destinationY));

			if (r<toR)
			{
				sourceX = sin( (M_PI/2.0f) * destinationX / toR ) * fromR ;

				color = retroPoint( fromScreen, sourceX + fromX, -sourceY + fromY ) ;
				retroPixel( toScreen, destinationX + toX, -destinationY +toY, color);

				color = retroPoint( fromScreen, sourceX + fromX, sourceY + fromY );
				retroPixel( toScreen, destinationX + toX, destinationY +toY, color);

				color = retroPoint( fromScreen, -sourceX + fromX, -sourceY + fromY ) ;
				retroPixel( toScreen, -destinationX + toX, -destinationY +toY, color);

				color = retroPoint( fromScreen, -sourceX + fromX, sourceY + fromY ) ;
				retroPixel( toScreen, -destinationX + toX, destinationY +toY, color);

			}
		}
	}
}

