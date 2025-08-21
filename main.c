#include "shell.h"

/**
 * find_command - Find command in PATH or return full path if exists
 * @cmd: Command to find
 * Return: Full path to command or NULL if not found
 */
char *find_command(char *cmd)
{
	char *path_env, *path_copy, *dir;
	char *full_path;
	struct stat st;
	
	/* If command contains '/', treat as absolute/relative path */
	if (strchr(cmd, '/'))
	{
		if (stat(cmd, &st) == 0)
			return (_strdup(cmd));
		return (NULL);
	}
	
	/* Get PATH environment variable */
	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);
		
	path_copy = _strdup(path_env);
	if (!path_copy)
		return (NULL);
		
	/* Search in each PATH directory */
	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = malloc(_strlen(dir) + _strlen(cmd) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		
		_strcpy(full_path, dir);
		_strcat(full_path, "/");
		_strcat(full_path, cmd);
		
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		
		free(full_path);
		dir = strtok(NULL, ":");
	}
	
	free(path_copy);
	return (NULL);
}

/**
 * main - Entry point of the simple shell
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t pid;
	int status;

	(void)argc;

	while (1)
	{
		/* Display prompt only in interactive mode */
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, ":) ", 3);
			fflush(stdout);
		}

		/* Read input */
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/* Remove newline */
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		/* Skip empty lines and trim spaces */
		if (line[0] == '\0')
			continue;

		/* Trim leading and trailing spaces */
		{
			char *trimmed = line;
			int len;
			char *args[1024];
			int argc = 0;
			char *token;
			char *cmd_path;
			
			while (*trimmed == ' ' || *trimmed == '\t')
				trimmed++;
			
			if (*trimmed == '\0')
				continue;

			len = strlen(trimmed);
			while (len > 0 && (trimmed[len - 1] == ' ' || trimmed[len - 1] == '\t'))
			{
				trimmed[len - 1] = '\0';
				len--;
			}

			/* Parse arguments */
			token = strtok(trimmed, " \t");
			while (token != NULL && argc < 1023)
			{
				args[argc] = token;
				argc++;
				token = strtok(NULL, " \t");
			}
			args[argc] = NULL;

			if (argc == 0)
				continue;

			/* Handle built-in commands */
			if (_strcmp(args[0], "exit") == 0)
			{
				free(line);
				exit(0);
			}

			if (_strcmp(args[0], "env") == 0)
			{
				print_env();
				continue;
			}

			/* Find command in PATH */
			cmd_path = find_command(args[0]);
			if (!cmd_path)
			{
				fprintf(stderr, "%s: No such file or directory\n", argv[0]);
				continue;
			}

			/* Fork and execute */
			pid = fork();
			if (pid == 0)
			{
				/* Child process */
				if (execve(cmd_path, args, environ) == -1)
				{
					fprintf(stderr, "%s: No such file or directory\n", argv[0]);
					free(cmd_path);
					_exit(127);
				}
			}
			else if (pid < 0)
			{
				perror("fork");
				free(cmd_path);
			}
			else
			{
				/* Parent process */
				wait(&status);
				free(cmd_path);
			}
		}
	}

	free(line);
	return (0);
}
