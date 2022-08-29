cmake_minimum_required(VERSION 3.15)
project(main)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
  src/*
)

set(PROJECT_LIST ${PROJECT_NAME})

foreach(_project ${PROJECT_LIST})
  add_executable(${_project})

  target_sources(${_project} PRIVATE ${PROJECT_SOURCES})

  target_include_directories(${_project} PRIVATE
    include
  )

  target_compile_options(${_project} PRIVATE)
  target_compile_definitions(${_project} PRIVATE)

  target_link_options(${_project} PRIVATE)
  target_link_directories(${_project} PRIVATE)
  target_link_libraries(${_project} PRIVATE)
endforeach()

set_target_properties(${PROJECT_NAME} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
