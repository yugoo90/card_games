cmake_minimum_required(VERSION 3.10)

# Project name
project(Card-Games)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include
include_directories(
    ${CMAKE_SOURCE_DIR}/include/model
    ${CMAKE_SOURCE_DIR}/include/controller
    ${CMAKE_SOURCE_DIR}/include/view
)

# Collect all .cpp files in the directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add Executeable 
add_executable(Card-Games ${SOURCES})