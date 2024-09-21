set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
cmake_minimum_required(VERSION 3.0.0)
project(dsa VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(dsa section-9-basic-sorting-algorithms/p1-selection-sort.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)