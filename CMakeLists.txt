cmake_minimum_required(VERSION 3.16)
project(HACKED VERSION 1.0.11)

set(CMAKE_CXX_STANDARD 17)

# Find Qt packages
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
if(NOT Qt6_FOUND)
    find_package(Qt5 REQUIRED COMPONENTS Core Widgets)
endif()

# Create executable
add_executable(HACKED HACKED.cpp)

# Link Qt libraries
target_link_libraries(HACKED Qt::Core Qt::Widgets)

# Platform-specific settings
if(WIN32)
    set_target_properties(HACKED PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
    
    # Deploy Qt DLLs on Windows
    if(Qt6_FOUND)
        find_program(WINDEPLOYQT_EXECUTABLE NAMES windeployqt HINTS "${Qt6_DIR}/../../../bin" "${Qt6_DIR}/../../bin")
    else()
        find_program(WINDEPLOYQT_EXECUTABLE NAMES windeployqt HINTS "${Qt5_DIR}/../../../bin" "${Qt5_DIR}/../../bin")
    endif()
    
    if(WINDEPLOYQT_EXECUTABLE)
        add_custom_command(TARGET HACKED POST_BUILD
            COMMAND ${WINDEPLOYQT_EXECUTABLE} --no-compiler-runtime --no-translations --no-system-d3d-compiler --no-opengl-sw --dir $<TARGET_FILE_DIR:HACKED> $<TARGET_FILE:HACKED>
            COMMENT "Deploying Qt libraries for Windows"
        )
    endif()
endif()

if(APPLE)
    set_target_properties(HACKED PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/Info.plist"
    )
    
    # Deploy Qt frameworks on macOS
    if(Qt6_FOUND)
        find_program(MACDEPLOYQT_EXECUTABLE NAMES macdeployqt HINTS "${Qt6_DIR}/../../../bin" "${Qt6_DIR}/../../bin")
    else()
        find_program(MACDEPLOYQT_EXECUTABLE NAMES macdeployqt HINTS "${Qt5_DIR}/../../../bin" "${Qt5_DIR}/../../bin")
    endif()
    
    if(MACDEPLOYQT_EXECUTABLE)
        add_custom_command(TARGET HACKED POST_BUILD
            COMMAND ${MACDEPLOYQT_EXECUTABLE} $<TARGET_BUNDLE_DIR:HACKED> -dmg
            COMMENT "Deploying Qt frameworks for macOS"
        )
    endif()
endif()

# Install targets
install(TARGETS HACKED
    RUNTIME DESTINATION bin
    BUNDLE DESTINATION .
) 