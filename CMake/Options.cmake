option(TEST_SERVER          "Build test server" 1)
option(LIB_SERENITY         "Build serenity library" 1)
option(LIB_DATABASE         "Build database library" 1)
option(LIB_SHARED           "Build shared library" 1)
option(TOOLS                "Build tools" 0)
option(WITH_DYNAMIC_LINKING "Enable dynamic library linking"    0)
option(WITH_WARNINGS        "Show all warnings during compile"  0)
option(WITH_CORE_DEBUG      "Include additional debug-code in core" 0)
set(WITH_SOURCE_TREE              "hierarchical" CACHE STRING "Build the source tree for IDE's.")
set_property(CACHE WITH_SOURCE_TREE PROPERTY STRINGS no flat hierarchical hierarchical-folders)
option(WITHOUT_GIT          "Disable the GIT testing routines" 0)