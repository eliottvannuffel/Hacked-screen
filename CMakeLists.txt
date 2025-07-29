cmake_minimum_required(VERSION 3.16)
project(HACKED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt5
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

# Enable automoc for Qt
set(CMAKE_AUTOMOC ON)

# Create executable
add_executable(HACKED HACKED.cpp)

# Link Qt5 libraries
target_link_libraries(HACKED Qt5::Core Qt5::Widgets)

# Set output directory
set_target_properties(HACKED PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
) 