#[[
                                    SerenityCore
                               ----------------------
           
    This file is part of the SerenityCore Project. See AUTHORS for more information
    
    This file is free software; as a special exception the author gives unlimited
    permission to copy and/or distribute it, with or without modifications,
    as long as this notice is preserved.
    
    This program is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY, to the extent permitted by law; without even the implied
    warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
]]#

cmake_minimum_required(VERSION 3.22)

# Set projectname (must be done AFTER setting configuration types)
project(SerenityCore)

# Set CMake-Macro directory
list(APPEND CMAKE_MODULE_PATH
        "${CMAKE_SOURCE_DIR}/CMake/Macros")

include(CheckCXXSourceRuns)
include(CheckIncludeFiles)

# Set default build options and print them out
include(CMake/Options.cmake)

include(InterfaceTargetsConfig)
include(CheckPlatform)
include(AutoCollect)
include(GroupSources)

include(CMake/ShowOptions.cmake)

add_subdirectory(Dependencies)

add_subdirectory(Sources)