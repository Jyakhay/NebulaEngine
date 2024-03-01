cmake_minimum_required(VERSION 3.5)

project(NebulaEngine)

set_property(GLOBAL PROPERTY USE_FOLDERS On)

#Add source files in Core directory
set(NEBULA_ENGINE_CORE_SOURCES
    "Core/NebulaEngine.cpp"
    "Core/NebulaEngine.h"
    "Core/Application.cpp"
    "Core/Application.h"
    "Core/Window.cpp"
    "Core/Window.h"
)

set(NEBULA_ENGINE_GRAPHICS_SOURCES
    "Graphics/GraphicsContext.cpp"
    "Graphics/GraphicsContext.h"
)

#Add source files in Debug directory
set(NEBULA_ENGINE_DEBUG_SOURCES
    "Debug/Logger.cpp"
    "Debug/Logger.h"
)

#Add source files in Platform directory
set(NEBULA_ENGINE_PLATFORM_SOURCES
    "Platform/FileSystem.cpp"
    "Platform/FileSystem.h"
)

#Add source files in Utility directory
set(NEBULA_ENGINE_UTILITY_SOURCES
    "Utilities/Time.cpp"
    "Utilities/Time.h"
)

#Third party files
set(NEBULA_ENGINE_THIRD_PARTY_SOURCES
    "ThirdParty/glad/src/glad.c"
    "ThirdParty/glad/include/glad/glad.h"
    "ThirdParty/glad/include/KHR/khrplatform.h"
)

#Set all source files of engine
set(NEBULA_ENGINE_SOURCES
    ${NEBULA_ENGINE_CORE_SOURCES}
    ${NEBULA_ENGINE_GRAPHICS_SOURCES}
    ${NEBULA_ENGINE_THIRD_PARTY_SOURCES}
    ${NEBULA_ENGINE_DEBUG_SOURCES}
    ${NEBULA_ENGINE_UTILITY_SOURCES}
    ${NEBULA_ENGINE_PLATFORM_SOURCES}
)

#Include directories
set(NEBULA_ENGINE_INCLUDE_DIRECTORIES
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${NEBULA_ENGINE_DEPENDENCY_DIRECTORY}/glfw/include/
    ${NEBULA_ENGINE_DEPENDENCY_DIRECTORY}/glm/
    "ThirdParty/glad/include/"
)

#Static/Dynamic build switch
if(BUILD_SHARED_LIBS)
    add_library(NebulaEngine SHARED ${NEBULA_ENGINE_SOURCES})
else()
    add_library(NebulaEngine STATIC ${NEBULA_ENGINE_SOURCES})
endif()

target_link_libraries(NebulaEngine glfw)

target_include_directories(NebulaEngine PRIVATE ${NEBULA_ENGINE_INCLUDE_DIRECTORIES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${NEBULA_ENGINE_SOURCES})