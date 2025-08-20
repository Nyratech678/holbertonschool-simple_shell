#!/bin/bash
# Test script for non-interactive mode of simple shell

echo "Testing Simple Shell - Non-Interactive Mode"
echo "==========================================="

# Test 1: Single command
echo "Test 1: Single command"
echo "ls" | ./hsh

echo -e "\n"

# Test 2: Command with arguments
echo "Test 2: Command with arguments"
echo "ls -l" | ./hsh

echo -e "\n"

# Test 3: Multiple commands
echo "Test 3: Multiple commands"
echo -e "ls\npwd\necho 'Multiple commands'" | ./hsh

echo -e "\n"

# Test 4: Built-in env command
echo "Test 4: Built-in env command"
echo "env" | ./hsh | head -5

echo -e "\n"

# Test 5: Error handling
echo "Test 5: Error handling"
echo "invalidcommand" | ./hsh

echo -e "\n"

# Test 6: Path resolution
echo "Test 6: Path resolution"
echo "/bin/echo 'Full path command'" | ./hsh

echo -e "\n"

echo "Non-interactive tests completed!"
