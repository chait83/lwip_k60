/*
 * File:        common.h
 * Purpose:     File to be included by all project files
 *
 * Notes:
 */

#ifndef _COMMON_H_
#define _COMMON_H_
#define portNOP()
/********************************************************************/

/*
 * Debug prints ON (#define) or OFF (#undef)
 */
#define DEBUG
#define DEBUG_PRINT
#define CPU_MK60N512VMD100
#define TOWER
/* 
 * Include the generic CPU header file 
 */



/* 
 * Include common utilities
 */
#include "eth.h"
#include "IO_Map.h"
#include <stdio.h>
#include <stdlib.h>

/********************************************************************/

#endif /* _COMMON_H_ */
