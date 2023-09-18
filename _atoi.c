#include "shell.h"

/**
 * is_interactive - checks if the shell is in interactive mode
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int is_interactive(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->read_fd <= 2);
}

/**
 * is_delimiter - checks if a character is a delimiter
 * @c: the character to check
 * @delim_str: the delimiter string
 * Return: 1 if true, 0 if false
 */
int is_delimiter(char c, char *delim_str)
{
	while (*delim_str)
	{
		if (*delim_str++ == c)
			return (1);
	}
	return (0);
}

/**
 * is_alphabetic - checks for an alphabetic character
 * @c: The character to check
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int is_alphabetic(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * custom_atoi - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int custom_atoi(char *str)
{
	int i, sign = 1, flag = 0, result = 0;

	for (i = 0; str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		return (-result);
	else
		return (result);
}

