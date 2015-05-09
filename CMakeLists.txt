cmake_minimum_required(VERSION 3.2)
project(bia_checker)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(bia_checker ${SOURCE_FILES} FileListHelper.cpp FileListHelper.h md5wrapper.h md5wrapper.cpp md5.h md5.cpp)