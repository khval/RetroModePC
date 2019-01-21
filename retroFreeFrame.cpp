/* :ts=4
 *  $VER: retroFreeFrame.c $Revision$ (19-Oct-2017)
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

/****** retromode/main/retroFreeFrame ******************************************
*
*   NAME
*      retroFreeFrame -- Description
*
*   SYNOPSIS
*      void retroFreeFrame(struct retroFrame * frame);
*
*   FUNCTION
*
*   INPUTS
*       frame - 
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

void retroFreeFrame(
       struct retroFrame * frame)
{

	sys_free( frame );
}

