# Specify CMake minimum version and project name
cmake_minimum_required(VERSION 3.18)
project(main)

# Generate executable file
add_executable(${PROJECT_NAME})

# Set source file
file(GLOB SOURCES CONFIGURE_DEPENDS
    src/*
)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

# Set header file directory
target_include_directories(${PROJECT_NAME}
    PRIVATE
)

# Set compile definition
target_compile_definitions(${PROJECT_NAME}
    PRIVATE
)

# Set link directory
target_link_directories(${PROJECT_NAME}
    PRIVATE
)

# Set link library
target_link_libraries(${PROJECT_NAME}
    PRIVATE
)

# Set target properties
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    POSITION_INDEPENDENT_CODE ON

    # Set output directory
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)

# Exclude debugging information when release type
if(CMAKE_BUILD_TYPE MATCHES Release)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        WIN32_EXECUTABLE TRUE
        MACOSX_BUNDLE TRUE
    )
endif()
