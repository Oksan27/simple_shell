#include "shell.h"
#include <stdio.h>

/**
 * _eperror - prints an error message to stderr
 * @msg: the error message to print
 * @status: the exit status
 */
void _eperror(char *msg, int status)
{
	if (msg)
	{
		while (*msg)
		{
			_eputchar(*msg);
			msg++;
		}
	}

	if (status >= 0)
	{
		char *exit_status = int_to_str(status);
		if (exit_status)
		{
			_eputs(": Exit ");
			_eputs(exit_status);
			free(exit_status);
		}
	}
	_eputchar('\n');
}

