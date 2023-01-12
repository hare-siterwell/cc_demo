cmake_minimum_required(VERSION 3.18)
project(main)

# 递归包含源文件
file(GLOB PROJECT_SOURCES CONFIGURE_DEPENDS
  src/*.c
  third_party/freertos/repo/list.c
  third_party/freertos/repo/queue.c
  third_party/freertos/repo/tasks.c
  third_party/freertos/repo/timers.c
  third_party/freertos/repo/portable/MSVC-MingW/port.c
  third_party/freertos/repo/portable/MemMang/heap_4.c)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})

# 头文件路径
target_include_directories(${PROJECT_NAME} PRIVATE
  include
  third_party/freertos/repo/include
  third_party/freertos/repo/portable/MSVC-MingW)

# 预定义
target_compile_definitions(${PROJECT_NAME} PRIVATE
  $<$<COMPILE_LANGUAGE:CXX>:__STRICT_ANSI__>)

target_link_libraries(${PROJECT_NAME} PRIVATE
  winmm
  hellostatic
  helloshared)

if ("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
  target_compile_options(${PROJECT_NAME} PRIVATE
    /utf-8)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_library(hellostatic src/hello_static.cpp)
target_include_directories(hellostatic PRIVATE include)

add_library(helloshared SHARED src/hello_shared.cpp)
target_include_directories(helloshared PUBLIC include)
target_compile_definitions(helloshared PRIVATE
  HELLO_SHARED_IMPLEMENTATION)
set_target_properties(helloshared PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
