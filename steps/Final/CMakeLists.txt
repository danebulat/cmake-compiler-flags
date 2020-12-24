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

# set build type to Release if not provided via command line
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Built type" FORCE)
endif()

# option for outputting compiler information at runtime
option(OUTPUT_COMPILER_INFO 
  "Output compiler information when launching the main executable." ON)

# check if compiler is part of GCC
if(CMAKE_COMPILER_IS_GNUCXX MATCHES 1)
  set(CXX_COMPILER_IS_GNU 1)
else()
  set(CXX_COMPILER_IS_GNU 0)
endif()

# output compiler information
if(CMAKE_CXX_COMPILER_LOADED)
  message(STATUS "Compiler path: ${CMAKE_CXX_COMPILER}")
  message(STATUS "Compiler ID: ${CMAKE_CXX_COMPILER_ID}")
  message(STATUS "Compiler version: ${CMAKE_CXX_COMPILER_VERSION}")
  message(STATUS "Compiler is part of GCC: ${CMAKE_COMPILER_IS_GNUCXX}")
endif()

# variables to store additional compiler flags
set(CXX_FLAGS)
set(CXX_FLAGS_DEBUG)
set(CXX_FLAGS_RELEASE)

# append global compiler flags to list
list(APPEND CXX_FLAGS "-fPIC" "-Wall")

# append compile flags depending on the selected compiler and build type
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
  list(APPEND CXX_FLAGS "-fno-rtti" "-fno-exceptions")
  list(APPEND CXX_FLAGS_DEBUG "-Wsuggest-final-types" "-Wsuggest-final-methods" "-Wsuggest-override")
  list(APPEND CXX_FLAGS_RELEASE "-O3" "-Wno-unused")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES Clang)
  list(APPEND CXX_FLAGS "-fno-rtti" "-fno-exceptions" "-Qunused-arguments" "-fcolor-diagnostics")
  list(APPEND CXX_FLAGS_DEBUG "-Wdocumentation")
  list(APPEND CXX_FLAGS_RELEASE "-O3" "-Wno-unused")
endif()

# output compiler flags  
include(CMakePrintHelpers)
cmake_print_variables(CXX_FLAGS)
cmake_print_variables(CXX_FLAGS_DEBUG)
cmake_print_variables(CXX_FLAGS_RELEASE)

# compile an object library for producing a shared and dynamic library
add_library(interp
    interpolate.h
    interpolate.cpp
  )

# set compile options for interp library
target_compile_options(interp PRIVATE ${CXX_FLAGS})

# generate executable
add_executable(main main.cpp)

# set compile options for the main executable
target_compile_options(main PRIVATE ${CXX_FLAGS}
     "$<$<CONFIG:Debug>:${CXX_FLAGS_DEBUG}>"
     "$<$<CONFIG:Release>:${CXX_FLAGS_RELEASE}>")

# link to shared library 
target_link_libraries(main interp)

# generate configuration file
configure_file(config.h.in config.h @ONLY)

# include binary  directory to find config.h
target_include_directories(main PRIVATE ${PROJECT_BINARY_DIR})
