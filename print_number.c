#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
int c = 0;
while (*s++)
c++;
return (c);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, params_t *params)
{
int negative = (*str == '-' && !params->unsign);
unsigned int num = _strlen(str);
if (!params->precision && *str == '0' && !str[1])
str = "";
if (negative)
{
str++;
num--;
}
if (params->precision != UINT_MAX)
while (num++ < params->precision)
*--str = '0';
if (negative)
*--str = '-';
if (!params->minus_flag)
return (print_number_right_shift(str, params));
else
return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, params_t *params)
{
char sp = ' ';
unsigned int x = 0, nega, nega1, i = _strlen(str);
if (params->zero_flag && !params->minus_flag)
sp = '0';
nega = nega1 = (!params->unsign && *str == '-');
if (nega && i < params->width && sp == '0' && !params->minus_flag)
str++;
else
nega = 0;
if ((!nega1 && params->plus_flag) ||
(!params->plus_flag && params->space_flag && !nega1))
i++;
if (nega && sp == '0')
x = x + _putchar('-');
if (params->plus_flag && !nega1 && sp == '0' && !params->unsign)
x = x + _putchar('+');
else if (!params->plus_flag && params->space_flag && !nega1 &&
!params->unsign && params->zero_flag)
x = x + _putchar(' ');
while (i++ < params->width)
x = x + _putchar(sp);
if (nega && sp == ' ')
x = x + _putchar('-');
if (!nega1 && params->plus_flag && sp == ' ' && !params->unsign)
x = x + _putchar('+');
else if (!params->plus_flag && params->space_flag &&
!params->unsign && !params->zero_flag && !nega1)
x = x + _putchar(' ');
x = x + _puts(str);
return (x);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, params_t *params)
{
char sp = ' ';
unsigned int num = 0, nega, nega2, i = _strlen(str);
if (params->zero_flag && !params->minus_flag)
sp = '0';
nega = nega2 = (!params->unsign && *str == '-');
if (nega && i < params->width && sp == '0' && !params->minus_flag)
str++;
else
nega = 0;
if (params->plus_flag && !nega2 && !params->unsign)
num = num + _putchar('+'), i++;
else if (params->space_flag && !nega2 && !params->unsign)
num = num + _putchar(' '), i++;
num = num + _puts(str);
while (i++ < params->width)
num = num + _putchar(sp);
return (num);
}
