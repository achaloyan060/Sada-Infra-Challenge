cmake_minimum_required(VERSION 3.5.1)

project(SADA_Infra C CXX)

#if(NOT MSVC)
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#else()
#  add_definitions(-D_WIN32_WINNT=0x600)
#endif()

# Include directories
include_directories(include)

# Targets
add_executable(challenge2 source/md5.cpp source/challenge2.cpp)
