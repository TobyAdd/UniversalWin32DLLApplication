cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTERSIONS OFF)

set(PROJECT_NAME UniversalWin32DLLApplication)
project(${PROJECT_NAME})

file(GLOB_RECURSE SOURCES 
    src/dllmain.cpp
)

set(WIN32 ON)
add_library(${PROJECT_NAME} SHARED ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")