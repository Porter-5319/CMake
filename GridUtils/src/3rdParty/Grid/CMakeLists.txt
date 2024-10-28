# Minimum CMake version required
cmake_minimum_required(VERSION 3.14)

# Project name and version
project(Grid VERSION 1.0.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
ADD_COMPILE_DEFINITIONS(GRID_EXPORTS)
# Set the output directories for the compiled library
set(GRID_OUTPUT_DIR ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${GRID_OUTPUT_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${GRID_OUTPUT_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${GRID_OUTPUT_DIR}/lib)

file(GLOB_RECURSE GRID_HDRS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE GRID_CPPS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(${PROJECT_NAME} SHARED ${GRID_HDRS} ${GRID_CPPS})

# Include the directory for 3rd-party headers
target_include_directories(${PROJECT_NAME} PUBLIC
    ${Eigen_INCLUDE_DIRS}
)

# Set the version of the shared library
set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    DEBUG_POSTFIX "_d"
    OUTPUT_NAME "${PROJECT_NAME}"
    PREFIX ""
    IMPORT_PREFIX ""
    IMPORT_SUFFIX ".lib"
)

# 将头文件拷贝到 ${GRID_OUTPUT_DIR}/lib
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${GRID_OUTPUT_DIR}/include
    COMMAND ${CMAKE_COMMAND} -E copy ${GRID_HDRS} ${GRID_OUTPUT_DIR}/include
    COMMENT "Copying file.txt to ${GRID_OUTPUT_DIR}/include"
)

