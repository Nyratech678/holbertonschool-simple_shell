# Simple Shell

![Shell](https://img.shields.io/badge/Shell-Bash-green.svg)
![C](https://img.shields.io/badge/Language-C-blue.svg)
![Ubuntu](https://img.shields.io/badge/OS-Ubuntu%2020.04-orange.svg)

## Description

This project is a simple UNIX command line interpreter (shell) written in C. It replicates the basic functionality of the `/bin/sh` shell, handling command execution in both interactive and non-interactive modes.

## Features

- Display a prompt and wait for user input
- Execute commands with arguments
- Handle the PATH environment variable
- Implement built-in commands (`exit`, `env`)
- Error handling with proper error messages
- Handle end-of-file condition (Ctrl+D)
- Memory management without leaks
- Both interactive and non-interactive modes

## Requirements

### General
- Allowed editors: `vi`, `vim`, `emacs`
- All files compiled on Ubuntu 20.04 LTS using `gcc`
- Compilation flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All files should end with a new line
- Code follows Betty style guidelines
- No memory leaks
- Maximum 5 functions per file
- All header files are include guarded

### Allowed Functions and System Calls
- All functions from `string.h`
- `access`, `chdir`, `close`, `closedir`, `execve`, `exit`, `_exit`
- `fflush`, `fork`, `free`, `getcwd`, `getline`, `getpid`, `isatty`
- `kill`, `malloc`, `open`, `opendir`, `perror`, `printf`, `fprintf`
- `vfprintf`, `sprintf`, `putchar`, `read`, `readdir`, `signal`
- `stat`, `lstat`, `fstat`, `strtok`, `wait`, `waitpid`, `wait3`
- `wait4`, `write`

## Installation

1. Clone the repository:
```bash
git clone https://github.com/Nyratech678/holbertonschool-simple_shell.git
```

2. Navigate to the project directory:
```bash
cd holbertonschool-simple_shell
```

3. Compile the shell:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

### Interactive Mode

```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($) ls -l
total 20
-rwxrwxr-x 1 user user 8760 Dec  5 12:00 hsh
-rw-rw-r-- 1 user user 1234 Dec  5 11:58 main.c
-rw-rw-r-- 1 user user 2345 Dec  5 11:59 shell.c
($) exit
$
```

### Non-Interactive Mode

```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c
$ cat commands.txt
/bin/ls
/bin/pwd
$ cat commands.txt | ./hsh
hsh main.c shell.c
/home/user/simple_shell
$
```

## Built-in Commands

### `exit`
Exits the shell.
```bash
($) exit
```

### `env`
Prints the current environment variables.
```bash
($) env
USER=user
HOME=/home/user
PATH=/usr/local/bin:/usr/bin:/bin
...
```

## File Structure

```
holbertonschool-simple_shell/
│
├── README.md              # Project documentation
├── AUTHORS                # Contributors list
├── man_1_simple_shell     # Manual page
├── shell.h                # Main header file
│
├── main.c                 # Program entry point
├── prompt.c               # Prompt display management
├── loop.c                 # Main shell loop
├── input.c                # Input reading and parsing
├── parse_line.c           # Command line parsing
├── execute.c              # Command execution
├── path.c                 # PATH handling
├── builtins.c             # Built-in commands
├── env_utils.c            # Environment utilities
├── errors.c               # Error handling
├── free_utils.c           # Memory management
│
├── tests/                 # Test scripts
│   ├── test_interactive.sh
│   └── test_non_interactive.sh
│
└── utils/                 # Utility functions
    ├── _strlen.c
    ├── _strcmp.c
    └── _strdup.c
```

## Error Handling

The shell handles errors similarly to `/bin/sh`, with the program name in error messages:

```bash
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
```

## Testing

### Interactive Testing
```bash
./hsh
```

### Non-Interactive Testing
```bash
echo "ls" | ./hsh
cat test_file | ./hsh
```

### Test Scripts
```bash
bash tests/test_interactive.sh
bash tests/test_non_interactive.sh
```

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Examples

### Basic Commands
```bash
($) ls
file1 file2 directory1
($) pwd
/home/user/simple_shell
($) echo "Hello World"
Hello World
```

### Commands with Arguments
```bash
($) ls -la
total 24
drwxrwxr-x 3 user user 4096 Dec  5 12:00 .
drwxr-xr-x 5 user user 4096 Dec  5 11:55 ..
-rwxrwxr-x 1 user user 8760 Dec  5 12:00 hsh
```

### Error Cases
```bash
($) invalidcommand
./hsh: 1: invalidcommand: not found
($) /bin/invalidpath
/bin/invalidpath: No such file or directory
```

## Learning Objectives

- Understand how a shell works
- Learn about processes and system calls
- Practice memory management in C
- Implement parsing and command execution
- Handle errors and edge cases
- Write clean, documented code following Betty style

## Resources

- [Unix Shell](https://en.wikipedia.org/wiki/Unix_shell)
- [Thompson Shell](https://en.wikipedia.org/wiki/Thompson_shell)
- [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)

## Authors

See [AUTHORS](AUTHORS) file for details.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

**Note**: This project was created as part of the Holberton School curriculum.
