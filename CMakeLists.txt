cmake_minimum_required(VERSION 3.10)
project(chiventure C)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR})
set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

find_package(Protobuf-c REQUIRED)
find_package(LibYAML REQUIRED)

set(CURSES_NEED_NCURSES TRUE)
set(CURSES_NEED_WIDE TRUE)
find_package(Curses REQUIRED)

set(CHIVENTURE_MODULES action_management checkpointing cli common game-state libobj ui wdl)

include_directories(include/)

add_subdirectory(src/action_management)
add_subdirectory(src/checkpointing)
add_subdirectory(src/cli)
add_subdirectory(src/common)
add_subdirectory(src/game-state)
add_subdirectory(src/libobj)
add_subdirectory(src/ui)
add_subdirectory(src/wdl)

# chiventure executable
add_executable(chiventure-bin src/chiventure.c)

foreach(module ${CHIVENTURE_MODULES})
    target_link_libraries(chiventure-bin ${module})
endforeach(module)

set_target_properties(chiventure-bin
        PROPERTIES OUTPUT_NAME chiventure)


# TESTS
find_package(Criterion REQUIRED)
enable_testing()
add_subdirectory(tests)





