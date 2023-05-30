#include "main.h"

/**
 * get_fidelity - Calculates the fidelity for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: Fidelity.
 */
int get_fidelity(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int fidelity = -1;

	if (format[curr_i] != '.')
		return (fidelity);

	fidelity = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			fidelity *= 10;
			fidelity += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			fidelity = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (fidelity);
}
