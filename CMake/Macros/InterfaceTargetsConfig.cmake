# An interface library to make the target com available to other targets
add_library(serenity-compile-option-interface INTERFACE)

# Use -std=c++11 instead of -std=gnu++11
set(CMAKE_CXX_EXTENSIONS OFF)

# An interface library to make the target features available to other targets
add_library(serenity-feature-interface INTERFACE)

target_compile_features(serenity-feature-interface
        INTERFACE
        cxx_std_20)

# An interface library to make the warnings level available to other targets
# This interface taget is set-up through the platform specific script
add_library(serenity-warning-interface INTERFACE)

# An interface used for all other interfaces
add_library(serenity-default-interface INTERFACE)
target_link_libraries(serenity-default-interface
        INTERFACE
        serenity-compile-option-interface
        serenity-feature-interface)

# An interface used for silencing all warnings
add_library(serenity-no-warning-interface INTERFACE)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
 target_compile_options(serenity-no-warning-interface
         INTERFACE
         /W0)
else()
 target_compile_options(serenity-no-warning-interface
         INTERFACE
         -w)
endif()

# An interface library to change the default behaviour
# to hide symbols automatically.
add_library(serenity-hidden-symbols-interface INTERFACE)

# An interface amalgamation which provides the flags and definitions
# used by the dependency targets.
add_library(serenity-dependency-interface INTERFACE)
target_link_libraries(serenity-dependency-interface
        INTERFACE
        serenity-default-interface
        serenity-no-warning-interface
        serenity-hidden-symbols-interface)

# An interface amalgamation which provides the flags and definitions
# used by the core targets.
add_library(serenity-core-interface INTERFACE)
target_link_libraries(serenity-core-interface
        INTERFACE
        serenity-default-interface
        serenity-warning-interface)
