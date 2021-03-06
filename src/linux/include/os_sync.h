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

#if !defined(_OS_SYNC_H)
#define _OS_SYNC_H

#include <os_types.h>
#include <os_thread.h>
#include <pthread.h>

#ifdef __cplusplus
extern "C"
{
#endif

/***
 * Mutex and Condition type definitions:
 */

#define OS_COND_ID (0x63636363)

typedef pthread_mutex_t* os_Mutex;

/* Define condition implementation type. */
struct os_Cond_s
{
    uint32_t cd_id;
    mpe_Bool cd_autoReset;
    mpe_Bool cd_state;
    os_ThreadId cd_owner;
    os_Mutex cd_mutex;
    pthread_cond_t cd_cond;
};

typedef struct os_Cond_s *os_Condition;
typedef struct os_Cond_s os_Condition_s;

#ifdef __cplusplus
}
#endif
#endif /* _OS_SYNC_H */

