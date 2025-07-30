cmake_minimum_required(VERSION 3.16)
project(HACKED VERSION 1.0.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable automoc for Qt
set(CMAKE_AUTOMOC ON)

# Find Qt6 first, fallback to Qt5
find_package(Qt6 COMPONENTS Core Widgets QUIET)
if (Qt6_FOUND)
    message(STATUS "Using Qt6")
    set(QT_VERSION "Qt6")
else()
    find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
    message(STATUS "Using Qt5")
    set(QT_VERSION "Qt5")
endif()

# Create executable
add_executable(HACKED HACKED.cpp)

# Link Qt libraries
if (Qt6_FOUND)
    target_link_libraries(HACKED Qt6::Core Qt6::Widgets)
else()
    target_link_libraries(HACKED Qt5::Core Qt5::Widgets)
endif()

# Platform-specific settings
if(WIN32)
    # Windows-specific settings
    set_target_properties(HACKED PROPERTIES
        WIN32_EXECUTABLE TRUE
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
    )
    # Copy Qt DLLs to output directory (for Windows deployment)
    if (Qt6_FOUND)
        add_custom_command(TARGET HACKED POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:Qt6::Core>
            $<TARGET_FILE:Qt6::Widgets>
            $<TARGET_FILE_DIR:HACKED>
        )
    endif()
elseif(APPLE)
    # macOS-specific settings
    set_target_properties(HACKED PROPERTIES
        MACOSX_BUNDLE TRUE
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
    )
    # Set macOS bundle properties
    set_target_properties(HACKED PROPERTIES
        MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist
    )
else()
    # Linux-specific settings
    set_target_properties(HACKED PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endif()

# Set application properties
set_target_properties(HACKED PROPERTIES
    OUTPUT_NAME "HACKED"
)

# Installation
install(TARGETS HACKED
    RUNTIME DESTINATION bin
    BUNDLE DESTINATION .
) 