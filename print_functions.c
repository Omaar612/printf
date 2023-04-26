#include "main.h"
/**
 * print_char - prints character
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_char(va_list ap, params_t *params)
{
	unsigned int i = 1, sum = 0, ch = va_arg(ap, int);
	char sp = ' ';

	if (params->minus_flag)
		sum += _putchar(ch);
	while (i++ < params->width)
		sum += _putchar(sp);
	if (!params->minus_flag)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - prints integer
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list ap, params_t *params)
{
	long num;

	if (params->l_modifier)
		num = va_arg(ap, long);
	else if (params->h_modifier)
		num = (short int)va_arg(ap, int);
	else
		num = (int)va_arg(ap, int);
	return (print_number(convert(num, 10, 0, params), params));
}

/**
 * print_string - prints string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list ap, params_t *params)
{
	unsigned int bb = 0, result = 0, i = 0, m;

	char *ptr = va_arg(ap, char *);
	char sp = ' ';
	(void)params;
	switch ((int)(!ptr))
		case 1:
			ptr = NULL_STRING;

	m = bb = _strlen(ptr);
	if (params->precision < bb)
		m = bb = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < bb; i++)
				result += _putchar(*ptr++);
		else
			result += _puts(ptr);
	}
	while (m++ < params->width)
		result += _putchar(sp);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < bb; i++)
				result += _putchar(*ptr++);
		else
			result += _puts(ptr);
	}
	return (result);
}

/**
 * print_percent - prints string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list ap, params_t *params)
{
(void)ap;
(void)params;
return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list ap, params_t *params)
{
int result = 0;
char *ptr = va_arg(ap, char *), *hexa;
if ((int)(!ptr))
return (_puts(NULL_STRING));
for (; *ptr; ptr++)
{
if ((*ptr > 0 && *ptr < 32) || *ptr >= 127)
{
result = result + _putchar('\\');
result = result + _putchar('x');
hexa = convert(*ptr, 16, 0, params);
if (!hexa[1])
result = result + _putchar('0');
result = result + _puts(hexa);
}
else
{
result = result + _putchar(*ptr);
}
}
return (result);
}
