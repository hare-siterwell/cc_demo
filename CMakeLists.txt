cmake_minimum_required(VERSION 3.18)
project(main)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
  src/*)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
  include)

set_target_properties(${PROJECT_NAME} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
