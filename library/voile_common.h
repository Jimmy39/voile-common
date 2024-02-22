/**
  @file voile_common.h
  @brief Common part for voile library
  
  - Provide some macro definitions and typedefs to make the voile library compatible with different processors and compilers.
  - Include devicelist.h to configure the voile library. 
  
  To use, include voile_common.h

  @author Jimmy Wang
  @version alpha-20240222
 
  @license MIT License

  Copyright (c) 2023-2024 Jimmy Wang

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
 */

#ifndef __VOILE_COMMON_H__
#define __VOILE_COMMON_H__

/**
  @brief include 'devicelist.h' to configure the voile library
  */
#include "devicelist.h"
#define doxygen_include_devicelist_h
#undef doxygen_include_devicelist_h

/**
  @brief If the Keil CX51 compiler is used, then manually typedef. Otherwise, use 'stdint.h'.
  @todo stdint for KEil CX51
  */
#ifdef __CX51__

#warning stdint for KEil CX51 not finish
typedef unsigned char      uint8_t;
typedef unsigned short int uint16_t;

#else  // __CX51__

#include <stdint.h>

#endif  // !__CX51__
#define doxygen_include_stdint_h
#undef doxygen_include_stdint_h

/**
  @brief Define bool
  If the Keil CX51 compiler is used, then it will be defined as uint8_t.
  */
#ifndef __CX51__
#define bool _Bool
#else
#define bool uint8_t
#endif  // __CX51__

/**
  @brief Variables you want to locate in ROM
  If the Keil compiler is used, then it will be defined as code
 */
#ifndef __CX51__
#define inROM const
#else
#define inROM code
#endif  // __CX51__

#endif  // !__VOILE_COMMON_H__
