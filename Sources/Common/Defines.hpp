#ifndef SERENITY_COMMON_DEFINES_HPP
#define SERENITY_COMMON_DEFINES_HPP

#include "CompilerDefines.hpp"

#if SERENITY_COMPILER == SERENITY_COMPILER_GNU
    //ToDo: Add GNU Compiler defines
#endif //SERENITY_COMPILER == SERENITY_COMPILER_GNU

#include <cstddef>
#include <cinttypes>
#include <climits>

#if SERENITY_PLATFORM == SERENITY_PLATFORM_WINDOWS
#   define SRY_PATH_MAX 260
#   define _USE_MATH_DEFINES
#else //SERENITY_PLATFORM != SERENITY_PLATFORM_WINDOWS
#   define SRY_PATH_MAX PATH_MAX
#endif //SERENITY_PLATFORM == SERENITY_PLATFORM_WINDOWS

#if SERENITY_COMPILER == SERENITY_COMPILER_GNU
#   define ATTR_PRINTF(F, V) __attribute__ ((__format__ (__printf__, F, V)))
#else
#   define ATTR_PRINTF(F, V)
#endif


#ifdef SERENITY_API_USE_DYNAMIC_LINKING
#   if SERENITY_COMPILER == SERENITY_COMPILER_MICROSOFT
#       define SRY_API_EXPORT __declspec(dllexport)
#       define SRY_API_IMPORT __declspec(dllimport)
#   elif SERENITY_COMPILER == SERENITY_COMPILER_GNU
#       define SRY_API_EXPORT __attribute__((bisibility("default")))
#       define SRY_API_IMPORT
#   else
#       error compiler not supported!
#   endif
#else
#   define SRY_API_EXPORT
#   define SRY_API_IMPORT
#endif

#ifdef SERENITY_API_EXPORT_COMMON
#   define SRY_COMMON_API SRY_API_EXPORT
#else
#   define SRY_COMMON_API SRY_API_IMPORT
#endif//SERENITY_API_EXPORT_COMMON

#ifdef SERENITY_API_EXPORT_SHARED
#   define SRY_SHARED_API SRY_API_EXPORT
#else
#   define SRY_SHARED_API SRY_API_IMPORT
#endif//SERENITY_API_EXPORT_SHARED

#ifdef SERENITY_API_EXPORT_DATABASE
#   define SRY_DATABASE_API SRY_API_EXPORT
#else
#   define SRY_DATABASE_API SRY_API_IMPORT
#endif//SERENITY_API_EXPORT_DATABASE

#ifdef SERENITY_API_EXPORT_PROTO
#   define SRY_PROTO_API SRY_API_EXPORT
#else
#   define SRY_PROTO_API SRY_API_IMPORT
#endif//SERENITY_API_EXPORT_PROTO

typedef int64_t int64;
typedef int32_t int32;
typedef int16_t int16;
typedef int8_t int8;
typedef uint64_t uint64;
typedef uint32_t uint32;
typedef uint16_t uint16;
typedef uint8_t uint8;

#endif //SERENITY_COMMON_DEFINES_HPP
