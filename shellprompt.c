#include "simpleshell.h"
/**
*prompt - prompts user to enter command
*@av: pointers to characters
*@env: environment
*Return: Always return 0
*/
void prompt(char **av, char **env)
{
	char *bufferadd = NULL;
	int n, s;
	size_t k = 0;
	ssize_t read_chars;
	pid_t newpid;
	char *argv[] = {NULL, NULL};

	while (1)
	{
		if(isatty(STDIN_FILENO))
		printf("Simpleshell#");
		read_chars = getline(&bufferadd, &k, stdin);
		if (read_chars == -1)
		{
			free(bufferadd);
			exit(EXIT_FAILURE);
		}
		n = 0;
		while (bufferadd[n])
		{ 
			if (bufferadd[n] == '\n')
			bufferadd[n] = 0;
			n++;
		}
		argv[0] = bufferadd;
		newpid  = fork();
		if (newpid == -1)
		{
			free(bufferadd);
			exit(EXIT_FAILURE);
		}
		if (newpid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			{
				printf("%s:No file in working directory\n", av[0]);
			}
			else
				wait(&s);
		}
	}
}
