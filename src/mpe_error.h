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

#ifndef _MPE_ERROR_H_
#define _MPE_ERROR_H_

/*
 * This file defines the MPE error code bindings to the OS error codes.
 * For exact values refer to the "os_error.h" header file for the target.
 * Some values may not have corresponding OS values, in which case an unused
 * value for the target platform should be selected as the representative value.
 */

#include <os_error.h>

/**
 * <i>MPE_SUCCESS<i/> indicates successful completion of an mpe_ or mpeos_
 * API call.  This is the value that should be compared against to determine
 * the API completion satus.  Implementation code should not assume any specific
 * value (e.g. zero).
 */
#define MPE_SUCCESS         OS_SUCCESS

/**
 * <i>MPE_EINVAL<i/> indicates that at least one input parameter to the API
 * was an invalid parameter value.
 */
#define MPE_EINVAL          OS_EINVAL

/**
 * <i>MPE_ENOMEM<i/> indicates that the API failed due to insufficient memory
 * resource availability.
 */
#define MPE_ENOMEM          OS_ENOMEM

/**
 * <i>MPE_EBUSY<i/> indicates that the device or resource (.e.g. mutex, etc)
 * is busy.
 */
#define MPE_EBUSY           OS_EBUSY

/**
 * <i>MPE_EMUTEX<i/> indicates that creation/deletion/acquisition of a mutex
 * via the API failed.
 */
#define MPE_EMUTEX          OS_EMUTEX

/**
 * <i>MPE_ECOND<i/> indicates that creation/deletion/acquisition of a condition
 * object via the API failed.
 */
#define MPE_ECOND           OS_ECOND

/**
 * <i>MPE_ECOND<i/> indicates that creation, deletion, processing of events
 * via the API failed.
 */
#define MPE_EEVENT          OS_EEVENT

/**
 * <i>MPE_ENODATA<i/> indicates that the associated resoure, queue, etc has no
 * data available.
 */
#define MPE_ENODATA         OS_ENODATA

/**
 * <i>MPE_ETIMEOUT<i/> indicates that the API has returned due to a timeout condition
 */
#define MPE_ETIMEOUT        OS_ETIMEOUT

/**
 * <i>MPE_ETHREADDEATH<i/> indicates that the thread in which this API is executing
 * has been marked for death.
 */
#define MPE_ETHREADDEATH    OS_ETHREADDEATH

#endif /* MPE_ERROR_H */
