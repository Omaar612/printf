#include "main.h"
void write_buff(char buff[], int *index);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
int i, j = 0, k = 0, s = 0, index;
int flags, width, precision, size;
char buff[index];
va_list ap;
if (format == NULL)
	return (-1);
va_start(ap, format);
for (i = 0; buff[s] != '\0' && format; i++)
{
if (format[i] != '%')
{
buff[s++] = format[i];
if (index == s)
{
	write_buff(buff, &s);
	j++;
}
}
else
{
write_buff(buff, &s);
flags = get_flags(format, &i);
width = get_width(format, &i, ap);
precision = get_precision(format, &i, ap);
size = get_size(format, &i);
++i;
k = handle_print(format, &i, ap, buff,
flags, width, precision, size);
if (k == -1)
return (-1);
j += k;
}
}
va_end(ap);
return (j);
}

/**
 * write_buff - Prints the contents of the buffer.
 * @buff: Array of chars.
 * @index: Index of the next char to be added.
 */
void write_buff(char buff[], int *index)
{
if (*index > 0)
write(1, &buff[0], *index);
*index = 0;
}
