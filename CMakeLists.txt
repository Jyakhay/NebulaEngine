cmake_minimum_required(VERSION 3.5)

set(NEBULA_ENGINE_ROOT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "Binaries")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "Binaries")

set(CMAKE_CXX_STANDARD 20)

project(NebulaEngine)

#Compiler Switch
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")

endif()

#Setup dependencies
add_subdirectory(Dependencies)

#Setup Source
add_subdirectory(Source)