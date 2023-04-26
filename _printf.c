#include "main.h"

/**
 * _printf - ...
 * @format: ...
 *
 * Return: ...
 */
int _printf(const char *format, ...)
{
	va_list a;
	int i = 0;
	char *c, *s;
	para poo = PARA_I;

	va_start(a, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (c = (char *)format; *c; c++)
	{
		i_par(&poo, a);
		if (*c != '%')
		{
			i += _putchar(*c);
			continue;
		}
		s = c;
		c++;
		while (g_f(c, &poo))
		{
			c++;
		}
		c = g_w(c, &poo, a);
		c = g_pre(c, &poo, a);
		if (g_mod(c, &poo))
			c++;
		if (!get_speci(c))
			i += pr_fr_to(s, c,
				poo.l_modifier || poo.h_modifier ? c - 1 : 0);
		else
			i += g_p_func(c, a, &poo);
	}
	_putchar(B_F);
	va_end(a);
	return (i);
}
