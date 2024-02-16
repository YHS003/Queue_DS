#ifndef _STD_QUEUE_TYPES_H
#define _STD_QUEUE_TYPES_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define ZERO_INIT 0
#define ZERO      0

typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;

typedef enum
{
    QUEUE_NOK,
    QUEUE_OK,
    QUEUE_NOT_CREATE,
    QUEUE_ARRAY_NOT_CREATE,
    QUEUE_FULL,
    QUEUE_EMPTY,
    QUEUE_NULL_POINTER,
    QUEUE_DESTROYED,
} QueueStatus;

#endif // _STD_QUEUE_TYPES_H
