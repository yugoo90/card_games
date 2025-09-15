cmake_minimum_required(VERSION 3.10)

# Project name
project(Card-Games)
# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Ensure CMake uses the debug flag
set(CMAKE_BUILD_TYPE Debug)
# Point to oatpp's CMake config directory
set(CMAKE_PREFIX_PATH "C:\\Users\\yugoo90\\oat2\\oatpp\\install")
# Find oatpp
find_package(oatpp CONFIG 1.4.0 REQUIRED)

# =========================
# Card-Games-Service
#==========================

# Collect all .cpp files in the directory
file(GLOB_RECURSE CORE_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/model/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/game/*.cpp"
)
# remove CLI and any server code from the lib:
list(FILTER CORE_SOURCES EXCLUDE REGEX ".*/src/game/main\\.cpp$")
list(FILTER CORE_SOURCES EXCLUDE REGEX ".*/src/server/.*")

# Add Executeable 
add_library(Card-Games-Service STATIC ${CORE_SOURCES})

target_include_directories(Card-Games-Service PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/model
    ${CMAKE_SOURCE_DIR}/src/controller
)

#=========================
# Card-Games-Server startup
#=========================
# Add Executeable 
add_executable(Card-Game-Server 
    src/server/server.cpp
#   src/server/ServerComponent.hpp
#   src/controller/Controller.hpp
)
# Include directories
target_include_directories(Card-Game-Server PRIVATE 
    ${CMAKE_SOURCE_DIR}/src 
    ${CMAKE_SOURCE_DIR}/include
)
# Link oatpp
target_link_libraries(Card-Game-Server PRIVATE
    Card-Games-Service
    oatpp::oatpp
    ssp
)