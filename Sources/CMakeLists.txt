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

add_custom_target(RevisionData.hpp ALL
        COMMAND "${CMAKE_COMMAND}" -DBUILDDIR="${CMAKE_BINARY_DIR}" -P "${CMAKE_SOURCE_DIR}/CMake/GenRevision.cmake" "${CMAKE_BINARY_DIR}"
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

set_target_properties(RevisionData.hpp
        PROPERTIES
        FOLDER
        "Application")

add_subdirectory(Common)
add_subdirectory(Application)