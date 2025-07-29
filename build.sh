#!/bin/bash

echo "Building HACKED application..."

# Check if Qt is installed
if ! command -v qmake &> /dev/null; then
    echo "Qt not found. Installing Qt5..."
    sudo apt update
    sudo apt install -y qt5-default qtbase5-dev qt5-qmake
fi

# Check if cmake is installed
if ! command -v cmake &> /dev/null; then
    echo "CMake not found. Installing cmake..."
    sudo apt update
    sudo apt install -y cmake build-essential
fi

# Create build directory
mkdir -p build
cd build

# Configure and build
cmake ..
make -j$(nproc)

if [ $? -eq 0 ]; then
    echo "Build successful!"
    echo "Run the application with: ./HACKED"
else
    echo "Build failed!"
    exit 1
fi 