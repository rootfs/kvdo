/*
 * Copyright (c) 2017 Red Hat, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA. 
 *
 * $Id: //eng/uds-releases/flanders/src/uds/threadOnce.h#2 $
 */

#ifndef THREAD_ONCE_H
#define THREAD_ONCE_H

#include "util/atomic.h"

#define ONCE_STATE_INITIALIZER ATOMIC_INITIALIZER(0)

typedef Atomic32 OnceState;

/**
 * Thread safe once only initialization.
 *
 * @param onceState    pointer to object to record that initialization
 *                     has been performed
 * @param initFunction called if onceState does not indicate
 *                     initialization has been performed
 *
 * @return             UDS_SUCCESS or error code
 *
 * @note Generally the following declaration of onceState is performed in
 *       at file scope:
 *
 *       static OnceState onceState = ONCE_STATE_INITIALIZER;
 **/
int performOnce(OnceState  *onceState, void (*initFunction) (void));

#endif /* THREAD_ONCE_H */
