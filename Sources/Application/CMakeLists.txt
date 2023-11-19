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


CollectSourceFiles(
        ${CMAKE_CURRENT_SOURCE_DIR}
        PRIVATE_SOURCES
        # Exclude
        ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)


GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Application
        ${PRIVATE_SOURCES}
)

if (NOT WIN32)
    target_compile_definitions(Application PRIVATE
            _SERENITY_APP_CONFIG="${CONF_DIR}/Application.conf"
            _SERENITY_APP_CONFIG_DIR="${CONF_DIR}/Application.conf.d"
    )
endif()

target_link_libraries(Application
        PRIVATE
        serenity-core-interface
        PUBLIC
        Common)

CollectIncludeDirectories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC_INCLUDES
        # Exclude
        ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)

target_include_directories(Application
        PUBLIC
        ${PUBLIC_INCLUDES}
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR})