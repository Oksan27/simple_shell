#include "shell.h"

/**
 * my_env - prints the environment
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int my_env(info_t *info)
{
	char **env = info->env;

	while (*env)
	{
		_puts(*env);
		_putchar('\n');
		env++;
	}

	return (0);
}

/**
 * my_setenv - sets an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int my_setenv(info_t *info)
{
	if (info->argc != 3)
	{
		print_error(info, "Usage: setenv VARIABLE VALUE");
		return (1);
	}

	if (_setenv(info, info->argv[1], info->argv[2]) == -1)
	{
		print_error(info, "setenv: Memory allocation error");
		return (1);
	}

	return (0);
}

/**
 * my_unsetenv - unsets an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int my_unsetenv(info_t *info)
{
	if (info->argc != 2)
	{
		print_error(info, "Usage: unsetenv VARIABLE");
		return (1);
	}

	if (_unsetenv(info, info->argv[1]) == -1)
	{
		print_error(info, "unsetenv: Variable not found");
		return (1);
	}

	return (0);
}
