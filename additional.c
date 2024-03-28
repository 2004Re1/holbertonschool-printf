#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"

extern unsigned int write_length;
int  _putchar(char c) 
{
	write_length++;
	return(write(1, &c, 1));
}

void _puts(char *str)
{
	int i;
	if (str == 0)
	{
		_puts("(null)");
		return;
	}
		for (i = 0; str[i] != 0; i++)
	{
		_putchar(str[i]);
	}
}

