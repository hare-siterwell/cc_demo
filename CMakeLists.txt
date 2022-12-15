cmake_minimum_required(VERSION 3.18)
project(main)

# 递归包含源文件
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
  src/*)

# 从源文件中排除
list(REMOVE_ITEM PROJECT_SOURCES)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})

# 头文件路径
target_include_directories(${PROJECT_NAME} PRIVATE
  src)

# 预定义
target_compile_definitions(${PROJECT_NAME} PRIVATE
  $<$<COMPILE_LANGUAGE:CXX>:__STRICT_ANSI__>)

if ("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
  target_compile_options(${PROJECT_NAME} PRIVATE
    /utf-8)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
