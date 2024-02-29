cmake_minimum_required(VERSION 3.5)

set(NEBULA_ENGINE_DEPENDENCY_DIRECTORY)

set(GLFW_INSTALL Off)

add_subdirectory(glfw)
set_target_properties(glfw PROPERTIES FOLDER "Dependencies/glfw")
set_target_properties(update_mappings PROPERTIES FOLDER "Dependencies/glfw")