#include "shell.h"
/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: contains potential arguments.for  constant function prototype.
 *  Return: 0 always
 */

int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * unset_alias - sets alias to string
 * @info: the  parameter structure
 * @str:  string alias
 *
 * Return: success 0,  error 1.
 */

int unset_alias(info_t *info, char *str)
{
	char *m, s;
	int ret;

	m = strchr(str, '=');

	if (!m)
		return (1);
	s = *m;
	*m = 0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*m = s;
	return (ret);
}

/**
 * set_alias - this code  sets alias to string
 * @info: this is the parameter structure
 * @str: string alias
 *
 * Return: on success 0, on error 1
 */

int set_alias(info_t *info, char *str)
{
	char *m;

	m= strchr(str, '=');
	if (!m)
		return (1);
			if (!*++m)
				return (unset_alias(info, str));
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) ==  NULL);
}

/**
 * print_alias -  prints the alias string in the code
 * @node: alias node
 *
 * Return: on success 0, 1 on error
 */

int print_alias(list_t *node)
{
	char *m = NULL, *r = NULL;

	if (node)
	{
		m = _strchr(node->str, '=');
		for (r = node->str; r <= m; r++)
		_putchar(*r);
		_putchar('\'');
		_puts(m + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - imitates the alias builtin (man alias)
 * @info: the structure containing arguments.  to maintain function prototype.
 *  Return: Always 0
 */

int _myalias(info_t *info)
{
	int a = 0;

	char *m = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (a = 1; info->argv[a]; a++)
	{
		m = _strchr(info->argv[a], '=');
		if (m)
			set_alias(info, info->argv[a]);
		else
			print_alias(node_starts_with(info->alias, info->argv[a], '='));
	}

	return (0);
}
