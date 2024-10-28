cmake_minimum_required(VERSION 3.14)

project(GridUtils LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THIRD_PARTY_DIR ${CMAKE_CURRENT_LIST_DIR}/3rdParty)

# 先编译第三方库
include(${CMAKE_CURRENT_LIST_DIR}/cmake/Eigen.cmake)

add_subdirectory(src)




