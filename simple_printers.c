#include "main.h"

/**
 * print_rot13 - ...
 * @ap: ...
 * @params: ...
 *
 * Return: ...
 */
int print_rot13(va_list ap, params_t *params)
{
char a[] =
"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
char *ar = va_arg(ap, char *);
int i, j;
int c = 0;
(void)params;
i = 0;
j = 0;
while (a[i])
{
if ((a[i] >= 'A' && a[i] <= 'Z')
|| (a[i] >= 'a' && a[i] <= 'z'))
{
j = a[i] - 65;
c += _putchar(ar[j]);
}
else
c += _putchar(a[i]);
i++;
}
return (c);
}

/**
 * print_from_to - ...
 * @start: ...
 * @stop: ...
 * @except: ...
 *
 * Return: ...
 */
int print_from_to(char *start, char *stop, char *except)
{
int i = 0;
while (start <= stop)
{
if (start != except)
i += _putchar(*start);
start++;
}
return (i);
}

/**
 * print_rev - ...
 * @ap: ...
 * @params: ...
 *
 * Return: ...
 */
int print_rev(va_list ap, params_t *params)
{
int j, i = 0;
char *s = va_arg(ap, char *);
(void)params;
if (s)
{
j = 0;
while (*s)
{
j++;
s++;
}
for (; j > 0; j--, s--)
i += _putchar(*s);
}
return (i);
}
