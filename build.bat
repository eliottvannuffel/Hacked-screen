@echo off
echo Building HACKED application for Windows...

REM Check if CMake is available
where cmake >nul 2>nul
if %errorlevel% neq 0 (
    echo CMake not found. Please install CMake from https://cmake.org/download/
    pause
    exit /b 1
)

REM Check if Qt is available
where qmake >nul 2>nul
if %errorlevel% neq 0 (
    echo Qt not found. Please install Qt from https://www.qt.io/download/
    pause
    exit /b 1
)

REM Create build directory
if not exist build mkdir build
cd build

REM Configure with CMake
echo Configuring with CMake...
cmake .. -G "Visual Studio 16 2019" -A x64

if %errorlevel% equ 0 (
    echo Building...
    cmake --build . --config Release
    
    if %errorlevel% equ 0 (
        echo Build successful!
        echo Run the application with: Release\HACKED.exe
    ) else (
        echo Build failed!
        pause
        exit /b 1
    )
) else (
    echo CMake configuration failed!
    pause
    exit /b 1
)

pause 