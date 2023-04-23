#include "main.h"
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
int i, j = 0;
int index = 0;
char buff[buff_size];
va_list ap;
if (format == NULL)
	return (-1);
va_start(ap, format);
for (i = 0; buff[buff_size] != '\0' && format; i++)
{
if (format[i] != '%')
{
}
}
va_end(ap);
return (j);
}
