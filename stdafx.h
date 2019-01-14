// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#define _CRT_NONSTDC_NO_DEPRECATE

#ifndef __linux__
#include "targetver.h"
#endif

#include <stdio.h>

#ifndef __linux__
#include <tchar.h>
#endif

#if defined(__linux__)
#define BOOL bool
#define sys_alloc(size) malloc(size)
#define sys_alloc_clear(size) calloc(1,size)
#define sys_free free
#endif
// TODO: reference additional headers your program requires here
