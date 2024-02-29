cmake_minimum_required(VERSION 3.5)

project(EngineTesting)

set(ENGINE_TESTING_SOURCE
    "main.cpp"
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "Binaries")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "Binaries")

add_executable(EngineTesting ${ENGINE_TESTING_SOURCE})

target_link_libraries(EngineTesting NebulaEngine)
target_include_directories(EngineTesting PRIVATE ${NEBULA_ENGINE_ROOT_DIRECTORY}/Source)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ENGINE_TESTING_SOURCE})