option(BUILD_32BIT "Build for 32 bit" OFF)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
option(COVERAGE "Use gcov" ON)
else()
option(COVERAGE "Use gcov" OFF)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
option(DOXYGEN "Build Doxygen" OFF)
else()
option(DOXYGEN "Build Doxygen" ON)
endif(s)

option(VERBOSE "Verbose message in cmake" OFF)
