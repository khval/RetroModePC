/* :ts=4
 *  $VER: retroOrFill.c $Revision$ (04-Nov-2017)
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
#include <vector>

/****** retromode/main/retroOrFill ******************************************
*
*   NAME
*      retroOrFill -- Description
*
*   SYNOPSIS
*      void retroOrFill(struct retroScreen * screen, int x, int y, 
*          int and_mask, unsigned char or_color);
*
*   FUNCTION
*
*   INPUTS
*       screen - 
*       x - 
*       y - 
*       and_mask - 
*       or_color - 
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

// nice on the stack on recursive call back

extern BOOL insideScreenAndReplaceColor(struct retroScreen *screen,unsigned char *sc_mem, int x,int y, unsigned char replace_color);
extern void AddXY( std::vector<FillNode> &list, int x, int y );

void retroOrFill(
       struct retroScreen * screen,
       int x,
       int y,
       int and_mask,
       unsigned char or_color)
{

	char replace_color;
	std::vector<FillNode> list;
	FillNode *node = NULL;
	unsigned char *sc_mem = screen -> Memory[screen -> double_buffer_draw_frame];

	and_mask |= or_color;	// prevents it from go in loop forever.

	if ((x>-1)&&(x<screen->realWidth)&&(y>-1)&&(y<screen->realHeight))
	{
		replace_color = sc_mem[ screen -> realWidth * y + x ]  & and_mask;
		if (replace_color == or_color) return;
	}
	else return;
	
	do
	{
		if ( list.size()==0 ) break;

		if (node = &list[0])
		{
			x = node -> x;
			y = node -> y;
			list.erase(list.begin());
		}

		sc_mem[ (screen -> realWidth * y) + x ] |= or_color;

		if (insideScreenAndReplaceColor(screen,sc_mem,x,y-1,replace_color)) AddXY( list, x, y-1 );
		if (insideScreenAndReplaceColor(screen,sc_mem,x,y+1,replace_color)) AddXY( list, x, y+1 );
		if (insideScreenAndReplaceColor(screen,sc_mem,x-1,y,replace_color)) AddXY( list, x-1, y );
		if (insideScreenAndReplaceColor(screen,sc_mem,x+1,y,replace_color)) AddXY( list, x+1, y );

	} while (list.size()>0);
}

