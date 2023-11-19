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

find_package(Boost)


add_library(boost INTERFACE)

target_link_libraries(boost
        INTERFACE
        ${Boost_LIBRARIES})

target_include_directories(boost
        INTERFACE
        ${Boost_INCLUDE_DIRS})

target_compile_definitions(boost
        INTERFACE
        -DBOOST_ALL_NO_LIB
        -DBOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE
        -DBOOST_ASIO_NO_DEPRECATED
        -DBOOST_BIND_NO_PLACEHOLDERS
        -DBOOST_SYSTEM_USE_UTF8)