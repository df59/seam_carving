# CMake version requirement
cmake_minimum_required(VERSION 3.10)

# Project name
project(seam_carve)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Source files
set(SOURCES
    image.cpp
    seam_carve.cpp
    main.cpp
)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES})