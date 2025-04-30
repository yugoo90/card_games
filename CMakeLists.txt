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

# Add Executeable 
add_executable(Card-Games
        
)