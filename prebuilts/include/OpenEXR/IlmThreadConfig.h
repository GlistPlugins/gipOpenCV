// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) Contributors to the OpenEXR Project.

// This file is auto-generated by the cmake configure step

#ifndef INCLUDED_ILMTHREAD_CONFIG_H
#define INCLUDED_ILMTHREAD_CONFIG_H 1

#pragma once

//
//
// C++ namespace configuration / options

#define ILMTHREAD_THREADING_ENABLED 1
#define ILMTHREAD_HAVE_POSIX_SEMAPHORES 1

//
// Current internal library namespace name
//
#define ILMTHREAD_INTERNAL_NAMESPACE_CUSTOM 0
#define ILMTHREAD_INTERNAL_NAMESPACE IlmThread_3_1

//
// Current public user namespace name
//

#define ILMTHREAD_NAMESPACE_CUSTOM 0
#define ILMTHREAD_NAMESPACE IlmThread

#if defined(__cplusplus) && (__cplusplus >= 201402L)
# define ILMTHREAD_DEPRECATED(msg) [[deprecated(msg)]]
#endif

#ifndef ILMTHREAD_DEPRECATED
# ifdef _MSC_VER
#  define ILMTHREAD_DEPRECATED(msg) __declspec(deprecated(msg))
# else
#  define ILMTHREAD_DEPRECATED(msg) __attribute__((deprecated(msg)))
# endif
#endif

#endif // INCLUDED_ILMTHREAD_CONFIG_H
