cmake_minimum_required(VERSION 3.20)

# Setup the project.
project(tetris VERSION 1.0)

# Specify C++ standard.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Download raylib with FetchContent.
include(FetchContent)

set(RAYLIB_VERSION 5.5)
FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS
)

FetchContent_MakeAvailable(raylib)

# Create executable.
set(EXECUTABLE_NAME tetris)
add_executable(${EXECUTABLE_NAME})

set_target_properties(${EXECUTABLE_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
)

target_sources(${EXECUTABLE_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/game.cpp
    ${PROJECT_SOURCE_DIR}/src/grid.cpp
    ${PROJECT_SOURCE_DIR}/src/blocks.cpp
)

target_include_directories(${EXECUTABLE_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_precompile_headers(${EXECUTABLE_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/include/includes.hpp
)

target_link_libraries(${EXECUTABLE_NAME} PRIVATE raylib)

# Web
if (EMSCRIPTEN)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1")
    set(CMAKE_EXECUTABLE_SUFFIX ".html") # This line is used to set your executable to build with the emscripten html template so that you can directly open it.
    
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/
    )
endif ()

# MacOS tomfoolery.
if (APPLE)
    target_link_libraries(${EXECUTABLE_NAME} "-framework IOKit")
    target_link_libraries(${EXECUTABLE_NAME} "-framework Cocoa")
    target_link_libraries(${EXECUTABLE_NAME} "-framework OpenGL")
endif()
