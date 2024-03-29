cmake_minimum_required(VERSION 3.16)

project(
  cplib
  VERSION 0.0
  DESCRIPTION "C++ Lib for Programming Contest"
  LANGUAGES C CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

include_directories("${CMAKE_SOURCE_DIR}")
include_directories("${CMAKE_SOURCE_DIR}/src")

include(${CMAKE_SOURCE_DIR}/cmake/options.cmake)
message(STATUS BUILD_32BIT=${BUILD_32BIT})

include(${CMAKE_SOURCE_DIR}/cmake/clang-format.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/coverage.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/doxygen.cmake)

# add test
add_subdirectory(3rdparty/googletest)
add_subdirectory(src)
add_subdirectory(tests)
