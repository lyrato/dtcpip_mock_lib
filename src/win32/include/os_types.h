// COPYRIGHT_BEGIN
//  DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
//  
//  Copyright (C) 2008-2009, Cable Television Laboratories, Inc. 
//  
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, version 2. This program is distributed
//  in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
//  even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE. See the GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License along
//  with this program.  If not, see  <http://www.gnu.org/licenses/>.
//  
//  Please contact CableLabs if you need additional information or 
//  have any questions.
//  
//      CableLabs
//      858 Coal Creek Cir
//      Louisville, CO 80027-9750
//      303 661-9100
//      oc-mail@cablelabs.com 
//  
//  If you or the company you represent has a separate agreement with CableLabs
//  concerning the use of this code, your rights and obligations with respect
//  to this code shall be as set forth therein. No license is granted hereunder
//  for any other purpose.
// COPYRIGHT_END

#if !defined(_OS_TYPES_H)
#define _OS_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

/*
 * Defined library symbol exportation macro.
 */
#ifdef __cplusplus
#    define OS_LIBEXPORT(type, symbol)  extern "C" __declspec(dllexport) type symbol
#else
#    define OS_LIBEXPORT(type, symbol)  extern __declspec(dllexport) type symbol
#endif

/* Integer type definitions */
#ifdef HAVE_STDINT_H
#include <stdint.h>
#else
typedef signed char int8_t; //  8 bit signed integer
typedef short int16_t; // 16 bit signed integer
typedef int int32_t; // 32 bit signed integer
typedef long long int64_t; // 64 bit signed integer
typedef unsigned char uint8_t; //  8 bit unsigned integer
typedef unsigned short uint16_t; // 16 bit unsigned integer
typedef unsigned uint32_t; // 32 bit unsigned integer
typedef unsigned long long uint64_t; // 64 bit unsigned integer
#endif

typedef unsigned int size_t;

/* The printf format specifiers for 64-bit integers */
#define FMT64 "%I64d"
#define FMTU64 "%I64u"

#ifdef __cplusplus
}
#endif

#endif /* _OS_TYPES_H */
