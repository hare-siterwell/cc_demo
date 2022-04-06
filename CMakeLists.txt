# Set CMake minimum required version and project name
cmake_minimum_required(VERSION 3.15)
project(main CXX)

# Generate executable file
add_executable(${PROJECT_NAME})

# Set sources
file(GLOB SOURCES CONFIGURE_DEPENDS
  src/*.cc
)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

# Set include directories
target_include_directories(${PROJECT_NAME} PRIVATE
  include
)

# Set compile definitions
target_compile_options(${PROJECT_NAME} PRIVATE)
target_compile_definitions(${PROJECT_NAME} PRIVATE)

# Set link libraries
target_link_options(${PROJECT_NAME} PRIVATE)
target_link_directories(${PROJECT_NAME} PRIVATE)
target_link_libraries(${PROJECT_NAME} PRIVATE)

# Set target properties
set_target_properties(${PROJECT_NAME} PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS OFF

  # Set output directory
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

# Exclude debugging information when release type
if(CMAKE_BUILD_TYPE MATCHES Release)
  set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
  )
endif()
