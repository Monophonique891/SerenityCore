find_package(MySQL REQUIRED COMPONENTS lib)

add_library(mysql INTERFACE)

target_link_libraries(mysql
        INTERFACE
        MySQL::MySQL)
