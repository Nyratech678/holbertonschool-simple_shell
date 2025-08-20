#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
void loop(char **argv);
ssize_t handle_input(char **line, size_t *len, char **argv);
void process_command(char **args, char **argv, int count);
char **parse_line(char *line);
int execute(char **args);
char *find_path(char *cmd);
int handle_builtin(char **args);
char *_getenv(const char *name);
void print_env(void);
void print_error(char *prog, char *cmd, unsigned int count, char *msg);
void free_args(char **args);
void display_prompt(void);
int _strlen(const char *s);
char *_strdup(const char *s);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *read_input(void);



#endif /* SHELL_H */
