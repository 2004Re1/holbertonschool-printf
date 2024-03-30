#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * checker - is function that checks flags.
 *@flag: is char contains flag.
 *@lol: variagr variables.
 *@counter:pointer for count of words.
 */
void checker(char flag, va_list *lol, int *counter)
{
	if (flag == 'd' || flag == 'i')
	{
		_printnum(va_arg(*lol, int), counter);
	}
	else if (flag == 's')
	{
	_puts(va_arg(*lol, char*), counter);
	}
	else if (flag == 'c')
	{
	_putchar((char)va_arg(*lol, int), counter);
	}
	else
	{
		if (flag != '%')
			_putchar('%', counter);
		_putchar(flag, counter);
	}
}

/**
 * _printf - Writes the formatted string to stdout.
 * @format: String that contains the text to be written to stdout.
 * Return: If successful, the total number of characters written is returned.
 */
int _printf(const char *format, ...)
{
	int i;
	int counter_org;
	va_list lol;

	va_start(lol, format);
	counter_org = 0;

	for (i = 0; format[i] != 0; i++)
	{
	char current = format[i];

	if (current == '%')
	{
		char flag;

		flag = format[++i];

		if (flag == 0)
			goto EDGE;
		checker(flag, &lol, &counter_org);
		continue;
	}

		_putchar(current, &counter_org);
	}

	va_end(lol);

EDGE:
	if (counter_org == 0)
	{
		return (-1);
	}
	return (counter_org);
}
