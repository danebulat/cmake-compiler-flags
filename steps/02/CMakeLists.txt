# set minimum cmake version
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# project name and language
project(cmake-compiler-flags LANGUAGES CXX)

# set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# always build shared libraries by default
set(BUILD_SHARED_LIBS ON)

# export symbols on Windows for shared libraries to work
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# compile an object library for producing a shared and dynamic library
add_library(interp
    interpolate.h
    interpolate.cpp
  )

# generate executable
add_executable(main main.cpp)

# link to shared library 
target_link_libraries(main interp)
