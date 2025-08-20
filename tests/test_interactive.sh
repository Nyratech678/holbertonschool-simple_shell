#!/bin/bash
# Test script for interactive mode of simple shell

echo "Testing Simple Shell - Interactive Mode"
echo "======================================="

# Test 1: Basic commands
echo "Test 1: Basic commands"
echo -e "ls\necho \"Hello World\"\npwd\nexit" | ./hsh

echo -e "\n"

# Test 2: Commands with arguments
echo "Test 2: Commands with arguments"
echo -e "ls -la\necho \"Test with args\"\nexit" | ./hsh

echo -e "\n"

# Test 3: Built-in commands
echo "Test 3: Built-in commands"
echo -e "env\nexit" | ./hsh

echo -e "\n"

# Test 4: Error handling
echo "Test 4: Error handling"
echo -e "invalidcommand\nexit" | ./hsh

echo -e "\n"

echo "Interactive tests completed!"
