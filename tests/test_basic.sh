#!/bin/bash
# Simple test script to check if the shell works without memory issues

echo "Testing basic functionality..."

# Test simple command
echo "ls" | timeout 5 ./hsh > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "✅ Basic command test: PASSED"
else
    echo "❌ Basic command test: FAILED"
fi

# Test with arguments
echo "ls -l" | timeout 5 ./hsh > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "✅ Command with arguments test: PASSED"
else
    echo "❌ Command with arguments test: FAILED"
fi

# Test built-in env
echo "env" | timeout 5 ./hsh > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "✅ Built-in env test: PASSED"
else
    echo "❌ Built-in env test: FAILED"
fi

# Test error handling
echo "invalidcommand" | timeout 5 ./hsh > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "✅ Error handling test: PASSED"
else
    echo "❌ Error handling test: FAILED"
fi

echo "All basic tests completed!"
