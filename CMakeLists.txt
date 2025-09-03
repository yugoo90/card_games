cmake_minimum_required(VERSION 3.10)

# Project name
project(Card-Games)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ensure CMake uses the deglbug flag
set(CMAKE_BUILD_TYPE Debug)

# Point to oatpp's CMake config directory
set(CMAKE_PREFIX_PATH "C:\\Users\\yugoo90\\oat2\\oatpp\\install")

# Find oatpp
find_package(oatpp CONFIG 1.4.0 REQUIRED)

# server startup

# Add Executeable 
add_executable(Card-Game-Server 
    src/server/server.cpp
    src/server/ServerComponent.hpp
    src/controller/Controller.hpp
)

# Link oatpp
target_link_libraries(Card-Game-Server 
    PRIVATE oatpp::oatpp
    ssp
)

# Include directories
target_include_directories(Card-Game-Server PRIVATE 
    ${CMAKE_SOURCE_DIR}/src 
    ${CMAKE_SOURCE_DIR/include}
)