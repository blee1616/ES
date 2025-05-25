#!/bin/bash

# Create build directory if it doesn't exist
mkdir -p build
cd build

# Run CMake to configure the project
cmake ../src

# Compile the project
make

# Move the compiled binary to the appropriate location
mv main ../

# Clean up build files
cd ..
rm -rf build