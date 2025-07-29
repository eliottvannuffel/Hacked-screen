#!/bin/bash

echo "Building HACKED application..."

# Detect operating system
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    OS="Linux"
elif [[ "$OSTYPE" == "darwin"* ]]; then
    OS="macOS"
elif [[ "$OSTYPE" == "msys" ]] || [[ "$OSTYPE" == "cygwin" ]]; then
    OS="Windows"
else
    OS="Unknown"
fi

echo "Detected OS: $OS"

# Platform-specific setup
if [[ "$OS" == "Linux" ]]; then
    # Linux setup
    if ! command -v qmake &> /dev/null; then
        echo "Qt not found. Installing Qt5..."
        sudo apt update
        sudo apt install -y qtbase5-dev qt5-qmake
    fi
    
    if ! command -v cmake &> /dev/null; then
        echo "CMake not found. Installing cmake..."
        sudo apt update
        sudo apt install -y cmake build-essential
    fi
    
elif [[ "$OS" == "macOS" ]]; then
    # macOS setup
    if ! command -v brew &> /dev/null; then
        echo "Homebrew not found. Please install Homebrew first:"
        echo "https://brew.sh/"
        exit 1
    fi
    
    if ! command -v qmake &> /dev/null; then
        echo "Qt not found. Installing Qt via Homebrew..."
        brew install qt
    fi
    
    if ! command -v cmake &> /dev/null; then
        echo "CMake not found. Installing cmake..."
        brew install cmake
    fi
    
elif [[ "$OS" == "Windows" ]]; then
    # Windows setup
    echo "Windows detected. Please ensure you have:"
    echo "1. Qt installed (https://www.qt.io/download)"
    echo "2. CMake installed (https://cmake.org/download/)"
    echo "3. Visual Studio or MinGW compiler"
    echo ""
    echo "Then run: cmake -B build && cmake --build build"
    exit 0
fi

# Check if cmake is available
if ! command -v cmake &> /dev/null; then
    echo "CMake not found. Please install CMake first."
    exit 1
fi

# Create build directory
mkdir -p build
cd build

# Configure and build
echo "Configuring with CMake..."
cmake ..

if [ $? -eq 0 ]; then
    echo "Building..."
    if [[ "$OS" == "Windows" ]]; then
        cmake --build . --config Release
    else
        make -j$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)
    fi
    
    if [ $? -eq 0 ]; then
        echo "Build successful!"
        if [[ "$OS" == "Windows" ]]; then
            echo "Run the application with: ./Release/HACKED.exe"
        elif [[ "$OS" == "macOS" ]]; then
            echo "Run the application with: ./HACKED.app/Contents/MacOS/HACKED"
        else
            echo "Run the application with: ./HACKED"
        fi
    else
        echo "Build failed!"
        exit 1
    fi
else
    echo "CMake configuration failed!"
    exit 1
fi 