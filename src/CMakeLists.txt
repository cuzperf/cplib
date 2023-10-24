project(cplib)

file(GLOB_RECURSE BASE_FILES "${CMAKE_SOURCE_DIR}/src/base/*")
add_library(cpbase STATIC ${BASE_FILES})

file(GLOB_RECURSE MATH_FILES "${CMAKE_SOURCE_DIR}/src/math/*")
add_library(cpmath STATIC ${MATH_FILES})

add_library(cplib STATIC
  empty.cpp
  cplib.h
  timer.hpp
)
target_link_libraries(cplib
  cpbase
  cpmath
)
