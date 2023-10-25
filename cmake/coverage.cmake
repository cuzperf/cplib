include(${CMAKE_SOURCE_DIR}/cmake/options.cmake)

if(COVERAGE)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
  set(LCOV_REMOVE_EXTRA "/usr/include/c++/*/*" "/usr/include/c++/*/*/*")
  if(CMAKE_VERBOSE_MAKEFILE)
    message(STATUS "  LCOV_REMOVE_EXTRA=${LCOV_REMOVE_EXTRA}")
  endif()
endif()

file(GLOB_RECURSE 3RD_PARTY_FILES "${CMAKE_SOURCE_DIR}/3rdparty/*")
file(GLOB_RECURSE TEST_FILES "${CMAKE_SOURCE_DIR}/tests/*")

list(APPEND LCOV_REMOVE_EXTRA ${3RD_PARTY_FILES} ${TEST_FILES})

# Generate coverage data
add_custom_target(coverage
  COMMAND lcov --directory . --capture --output-file coverage.info
  COMMAND lcov --remove coverage.info ${LCOV_REMOVE_EXTRA} --output-file coverage.info
  COMMAND genhtml coverage.info --output-directory coverage_report
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
