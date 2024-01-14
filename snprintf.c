#include "shell.h"

/**
 * _snprintf - Prints everything in a format into a buffer
 * @buffer: the buffer to print into
 * @size: the size of the format
 * @format: the string to print
 * Return: the number of written
*/

int _snprintf(char *buffer, size_t size, const char *format, ...)
{
	va_list args;
	int written = 0, remaining, len;
	const char *c, *string;
	char character;

	va_start(args, format);
	if (size == 0)
		return (0);
	remaining = size - 1;
	for (c = format; *c != '\0'; ++c)
	{
		if (*c == '%' && *(c + 1) == 's')
		{
			string = va_arg(args, const char *);
			len = _strcpy((buffer + written), remaining, string);
			written += len;
			remaining -= len;
			c++;
		}
		else if (*c == '%' && *(c + 1) == 'c')
		{
			character = (char)va_arg(args, int);
			if (remaining > 0)
			{
				buffer[written++] = character;
				remaining--;
			}
			c++;
		}
		else
		{
			if (remaining > 0)
			{
				buffer[written++] = *c;
				remaining--;
			}
		}
	}
	buffer[written] = '\0';
	va_end(args);
	return (written);
}
