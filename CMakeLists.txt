cmake_minimum_required(VERSION 3.14.0)

include("${CMAKE_CURRENT_LIST_DIR}/cmake/ProjectSetup.cmake")

setup_dependencies()

project(
  Senseless
  VERSION 0.1.0
  LANGUAGES C CXX)

string(
  COMPARE EQUAL
          "${CMAKE_SOURCE_DIR}"
          "${PROJECT_SOURCE_DIR}"
          SL_IS_TOPLEVEL_PROJECT)

setup_project()

set(SL_PUBLIC_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/src")

if(SL_ENABLE_TESTS)
  enable_testing()
  add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/test")
endif()
