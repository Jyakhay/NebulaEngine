cmake_minimum_required(VERSION 3.5)

project(NebulaEngine)

set_property(GLOBAL PROPERTY USE_FOLDERS On)

#Add source files in Core directory
set(NEBULA_ENGINE_CORE_SOURCES
    "Core/NebulaEngine.cpp"
    "Core/NebulaEngine.h"
)

#Set all source files of engine
set(NEBULA_ENGINE_SOURCES
    ${NEBULA_ENGINE_CORE_SOURCES}
)


#Static/Dynamic build switch
if(BUILD_SHARED_LIBS)
    add_library(NebulaEngine SHARED ${NEBULA_ENGINE_SOURCES})
else()
    add_library(NebulaEngine STATIC ${NEBULA_ENGINE_SOURCES})
endif()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${NEBULA_ENGINE_SOURCES})