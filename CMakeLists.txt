cmake_minimum_required(VERSION 3.10)
project(MultiTargetProject VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Define source files for different targets
set(SOURCES_TARGET1
    main.c
    helpers.c
)

set(SOURCES_TARGET2
    main.c
    helpers.c
)


# Define the first executable target
add_executable(release ${SOURCES_TARGET1})

# Define the second executable target
add_executable(debug ${SOURCES_TARGET2})

add_executable(debug_offset ${SOURCES_TARGET2})


# Add include directories common to both targets
include_directories(
    /usr/local/include/notcurses
)
set(MY_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/notcurses/build")
link_directories(${MY_LIBRARY_DIR})

# Link libraries common to both targets
target_link_libraries(release
    -pthread
    -lnotcurses
    -lnotcurses-core
)

target_link_libraries(debug
    -pthread
    -lnotcurses
    -lnotcurses-core
)

target_link_libraries(debug_offset
  -pthread
  -lnotcurses
  -lnotcurses-core
)

# Set different compiler flags for each target
target_compile_options(release PRIVATE -Wall -Wextra -O2 -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600)
target_compile_options(debug PRIVATE -Wall -Wextra -DDEBUG_MODE -ggdb -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600)
target_compile_options(debug_offset PRIVATE -Wall -Wextra -DDEBUG_OFFSET -ggdb -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600)



# Default build type to Release if not specified
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()
