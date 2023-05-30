#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @diameter: get diameter.
 * @fidelity: fidelity specifier
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char buffer[],
	int flags, int diameter, int fidelity, int size)
{ /* char is stored at left and paddind at buffer's right */
	int i = 0;
	char padd = ' ';

	UNUSED(fidelity);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (diameter > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < diameter - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], diameter - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], diameter - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
