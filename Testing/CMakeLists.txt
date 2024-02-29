cmake_minimum_required(VERSION 3.5)

get_filename_component(NEBULA_ENGINE_ROOT_DIRECTORY ../ ABSOLUTE)

project(EngineTesting)

add_subdirectory(${NEBULA_ENGINE_ROOT_DIRECTORY} Dependencies/Nebula)
set_target_properties(NebulaEngine PROPERTIES FOLDER "Dependencies")

add_subdirectory(Source)