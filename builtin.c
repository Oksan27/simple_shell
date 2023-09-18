#include "shell.h"

/**
 * my_exit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info->args[0] != "exit"
 */
int my_exit(info_t *info)
{
	int exit_code;

	if (info->args[1]) /* If there is an exit argument */
	{
		exit_code = custom_atoi(info->args[1]);
		if (exit_code == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->args[1]);
			_eputchar('\n');
			return (1);
		}
		info->error_num = exit_code;
		return (-2);
	}
	info->error_num = -1;
	return (-2);
}

/**
 * my_cd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int my_cd(info_t *info)
{
	char *current_dir, *target_dir, buffer[1024];
	int chdir_ret;

	current_dir = getcwd(buffer, 1024);
	if (!current_dir)
		_puts("TODO: >>getcwd failure message here<<\n");
	if (!info->args[1])
	{
		target_dir = _getenv(info, "HOME=");
		if (!target_dir)
			chdir_ret = /* TODO: What should this be? */
				chdir((target_dir = _getenv(info, "PWD=")) ? target_dir : "/");
		else
			chdir_ret = chdir(target_dir);
	}
	else if (_strcmp(info->args[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(current_dir);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD="));
		_putchar('\n');
		chdir_ret = /* TODO: What should this be? */
			chdir((target_dir = _getenv(info, "OLDPWD=")) ? target_dir : "/");
	}
	else
		chdir_ret = chdir(info->args[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->args[1]);
		_eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * my_help - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int my_help(info_t *info)
{
	char **arg_array;

	arg_array = info->args;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* Temporary unused variable workaround */
	return (0);
}

