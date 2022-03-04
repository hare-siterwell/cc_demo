cmake_minimum_required(VERSION 3.18)
project(main)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

# Set source files
file(GLOB SOURCES CONFIGURE_DEPENDS
    src/*.cc
)

add_executable(${PROJECT_NAME} ${SOURCES})

# Set include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    src
)
