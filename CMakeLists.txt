cmake_minimum_required(VERSION 2.8)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

project (HackerRankCommons)

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")
endif()

message ("Starting build on "+${CMAKE_SYSTEM})

message ("${CMAKE_CXX_FLAGS_RELEASE} :: ${CMAKE_CXX_FLAGS}")
message ("GTEST_FOLDER = ${GTEST_FOLDER}")
message ("${CMAKE_CXX_COMPILER}")
message ("${CMAKE_VS_PLATFORM_TOOLSET}")
message ("-------------")

add_subdirectory (util)
add_subdirectory (Test)
