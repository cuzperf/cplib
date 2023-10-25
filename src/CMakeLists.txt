project(cplib)

file(GLOB_RECURSE BASE_FILES "${CMAKE_SOURCE_DIR}/src/base/*")
add_library(cpbase STATIC ${BASE_FILES})
# ingore integer overflow
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  target_compile_options(cpbase PRIVATE -fwrapv)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(cpbase PRIVATE /EHsc)
endif()

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
