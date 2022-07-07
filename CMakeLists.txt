cmake_minimum_required(VERSION 3.15)
project(main)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
  src/*
)

add_executable(${PROJECT_NAME})
set(EXE_LISTS ${PROJECT_NAME})

foreach(_var ${EXE_LISTS})
  target_sources(${_var} PRIVATE ${SOURCES})

  target_include_directories(${_var} PRIVATE
    include
  )

  target_compile_options(${_var} PRIVATE)
  target_compile_definitions(${_var} PRIVATE)

  target_link_options(${_var} PRIVATE)
  target_link_directories(${_var} PRIVATE)
  target_link_libraries(${_var} PRIVATE)

  set_target_properties(${_var} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
  )
endforeach()
