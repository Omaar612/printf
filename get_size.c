#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
int size = 0;
int u = *s + 1;
if (format[u] == 'l')
size = S_LONG;
else if (format[u] == 'h')
size = S_SHORT;
if (size == 0)
*s = u - 1;
else
*s = u;
return (size);
}
