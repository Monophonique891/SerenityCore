#ifndef SERENITY_COMMON_COMPILER_DEFINES_HPP
#define SERENITY_COMMON_COMPILER_DEFINES_HPP


#define SERENITY_PLATFORM_WINDOWS   0
#define SERENITY_PLATFORM_UNIX      1

#if defined(_WIN64)
#   define SERENITY_PLATFORM SERENITY_PLATFORM_WINDOWS
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#   define SERENITY_PLATFORM SERENITY_PLATFORM_WINDOWS
#else
#   define SERENITY_PLATFORM SERENITY_PLATFORM_UNIX
#endif //_WIN64

#define SERENITY_COMPILER_MICROSOFT 0
#define SERENITY_COMPILER_GNU       1

#ifdef _MSC_VER
#   define SERENITY_COMPILER SERENITY_COMPILER_MICROSOFT
#elif defined(__GNUC__)
#   define SERENITY_COMPILER SERENITY_COMPILER_GNU
#   define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#else
#   error "FATAL ERROR: Unknown Compiler!"
#endif //_MSC_VER


#endif //SERENITY_COMMON_COMPILER_DEFINES_HPP