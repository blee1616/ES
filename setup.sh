#!/bin/bash

# This script sets up the project environment and dependencies for the energy simulation application.

# Update package list and install necessary packages
sudo apt-get update
sudo apt-get install -y build-essential cmake python3 python3-pip

# Navigate to the backend directory
cd backend/python

# Install Python dependencies
pip3 install -r requirements.txt

# Navigate to the C++ directory and compile the C++ code
cd ../cpp
bash compile.sh

# Navigate back to the root directory
cd ../../

echo "Setup completed successfully."