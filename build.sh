#!/bin/bash

# SplitWise Build Script
# This script compiles the SplitWise application with dark mode support

echo "=== Building SplitWise Application ==="

# Navigate to the MainFiles directory
cd "$(dirname "$0")/MainFiles" || exit 1

# Clean previous builds
echo "Cleaning previous builds..."
rm -f *.o splitwise test_theme

# Compile the main application
echo "Compiling SplitWise..."
g++ -o splitwise main.cpp Login.cpp expense.cpp Dashboard.cpp User.cpp Theme.cpp

if [ $? -eq 0 ]; then
    echo "✓ SplitWise compiled successfully!"
    echo "✓ Executable: ./MainFiles/splitwise"
    
    # Compile the test suite
    echo "Compiling test suite..."
    g++ -o test_theme test_theme.cpp Theme.cpp
    
    if [ $? -eq 0 ]; then
        echo "✓ Test suite compiled successfully!"
        echo "✓ Test executable: ./MainFiles/test_theme"
        echo ""
        echo "=== Build Complete ==="
        echo "Run './MainFiles/splitwise' to start the application"
        echo "Run './MainFiles/test_theme' to run the theme tests"
    else
        echo "⚠ Warning: Test suite compilation failed"
    fi
else
    echo "✗ Error: SplitWise compilation failed"
    exit 1
fi