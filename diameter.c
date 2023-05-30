#include "main.h"

/**
 * get_diameter - Calculates the diameter for printing
 * @format: Format strings to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: diameter.
 */
int get_diameter(const char *format, int *i, va_list list)
{
	int curr_i;
	int diameter = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			diameter *= 10;
			diameter += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			diameter = va_arg(list, int);
			break;
		}
		else
			break;
	}
	
	*i = curr_i - 1;
	return (diameter);
}
