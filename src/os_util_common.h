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

#if !defined(_OS_UTIL_COMMON_H)
#define _OS_UTIL_COMMON_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <os_types.h>   /* Resolve basic type references. */
#include <setjmp.h>     /* Include Windows setjmp.h header. */

/***
 * Type definitions:
 */

/* setjmp/longjmp implementation buffer. */
typedef jmp_buf os_JmpBuf;

/* STB configuration information structure. */
typedef struct os_STBConfig_s
{
    void *os_reserved[4]; /* Reserved space. */
} os_STBConfig;

/**
 * A power state change is identified by trapping a power key
 * press in the key events handler. togglePowerMode() will use the
 * Event Dispatcher to send events to a registered listener in the Java layer.
 */
void togglePowerMode(void);

/**
 * A configuration structure for managing the porting environment.
 */
typedef struct os_EnvConfig_s
{
    char *os_config; /* The location of the mpeenv.ini file. */
    int32_t os_numModules; /* The number of moduels in the os_modulePath. */
    char **os_modulePath; /* An array of paths for resolving DLLs. */
} os_EnvConfig;

/**
 * Initialize the porting environment configuration.
 *
 * @param env A pointer to the structure containing the information
 * necessary for intiializing the ports environment.
 */
void os_envInit(os_EnvConfig *env);

mpe_Error removeFiles(char *dirPath);

/**
 * Return the number of tuners from the underlying target platform.
 */
int os_getNumTuners(void);

#ifdef __cplusplus
}
#endif

#endif /* _OS_UTIL_COMMON_H */
