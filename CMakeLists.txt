cmake_minimum_required(VERSION 3.10)

# Project name
project(Card-Games)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Point to oatpp's CMake config directory
set(CMAKE_PREFIX_PATH "C:/Users/yugoo90/oat2/oatpp/install")

# Find oatpp
find_package(oatpp REQUIRED)

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

# Link oatpp
target_link_libraries(Card-Games
    oatpp::oatpp
)