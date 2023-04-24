#include "main.h"

/* PRINT CHAR */

/**
 * print_char - Prints a char
 * @ap: List a of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list ap, char buff[],
int flags, int width, int precision, int size)
{
char c = va_arg(ap, int);
return (handle_write_char(c, buff, flags, width, precision,
size));
}

/* PRINT A STRING */
/**
 * print_string - Prints a string
 * @ap: List a of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list ap, char buff[],
int flags, int width, int precision, int size)
{
int m = 0, i;
char *ptr = va_arg(ap, char *);
UNUSED(size);
UNUSED(buff);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
if (ptr == NULL)
{
ptr = "(null)";
if (precision >= 6)
ptr = "      ";
}
while (ptr[m] != '\0')
m++;
if (precision >= 0 && precision < m)
m = precision;
if (width > m)
{
if (flags & F_MINUS)
{
write(1, &ptr[0], m);
for (i = width - m; i > 0; i--)
write(1, " ", 1);
return (width);
}
else
{
for (i = width - m; i > 0; i--)
write(1, " ", 1);
write(1, &ptr[0], m);
return (width);
}
}
return (write(1, ptr, m));
}
/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @ap: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list ap, char buff[],
	int flags, int width, int precision, int size)
{
unsigned long int val;
int neg = 0;
int i = INDEX - 2;
long int j = va_arg(ap, long int);
j = convert_size_number(j, size);
if (j == 0)
buff[i--] = '0';
buff[INDEX - 1] = '\0';
val = (unsigned long int)j;
if (j < 0)
{
val = (unsigned long int)((-1) * j);
neg = 1;
}
while (val > 0)
{
buff[i--] = (val % 10) + '0';
val /= 10;
}
i++;
return (write_number(neg, i, buff, flags, width, precision, size));
}

/* PRINT PERCENT SIGN */
/**
 * print_percent - Prints a percent sign
 * @ap: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list ap, char buff[],
int flags, int width, int precision, int size)
{
UNUSED(size);
UNUSED(buff);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
return (write(1, "%%", 1));
}

/* PRINT BINARY */
/**
 * print_binary - Prints an unsigned number
 * @ap: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list ap, char buff[],
int flags, int width, int precision, int size)
{
unsigned int p[32];
UNUSED(size);
UNUSED(buff);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
unsigned int j, k, c, i, s;
k = 2147483648;
j = va_arg(ap, unsigned int);
p[0] = j / k;
for (i = 1; i < 32; i++)
{
k /= 2;
p[i] = (j / k) % 2;
}
for (i = 0, s = 0, c = 0; i < 32; i++)
{
s += p[i];
if (s || i == 31)
{
char z = '0' + p[i];
write(1, &z, 1);
c++;
}
}
return (c);
}
