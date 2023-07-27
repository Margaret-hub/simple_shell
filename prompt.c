#include "simpleshell.h"

/**
* main - includes all codes
*@ac: argument
*@av: argument
*@env: environment
*Return: always return 0
*/

int main(int ac, char **av, char **env)
{
	if (ac == 1)
		prompt(av, env);
	return (0);
}
