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

#if !defined(_OS_ERROR_H)
#define _OS_ERROR_H

#define OS_ERRBASE  (100)

#define OS_SUCCESS			(0)
#define OS_EINVAL			(OS_ERRBASE+1)
#define OS_ENOMEM     		(OS_ERRBASE+2)
#define OS_EBUSY  			(OS_ERRBASE+3)
#define OS_EMUTEX           (OS_ERRBASE+4)
#define OS_ECOND            (OS_ERRBASE+5)
#define OS_EEVENT           (OS_ERRBASE+6)
#define OS_ETIMEOUT         (OS_ERRBASE+7)
#define OS_ENODATA          (OS_ERRBASE+8)
#define OS_ETHREADDEATH     (OS_ERRBASE+9)

#endif /* OS_ERROR_H */
