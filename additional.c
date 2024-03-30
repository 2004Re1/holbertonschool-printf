#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"
/**
 * _putchar - is function.
 *@c: is variable.
 */

int  _putchar(char c, int *counter) 
{
    (*counter)++;
	return(write(1, &c, 1));
}
/**
 *_puts - is func.
 *@str: is string
 */
void _puts(char *str,int *counter)
{
	int i;
	if (str == 0)
	{
		_puts("(null)",counter);
		return;
	}
		for (i = 0; str[i] != 0; i++)
	{
		_putchar(str[i],counter);
	}
}

void _number_len(int x,int *len)
{
    int temp;
    temp = x;
    do {
        (*len)++;
        temp /= 10;
    } while (temp != 0);
}

void Negative_check(int *x,int *isNegative, int *len)
{
     if (*x < 0) {
        *isNegative = 1;
        (*len)++;
        if (*x != INT_MIN)
        {
            *x = -(*x);
        }
    }
}

void _printnum(int x, int *counter)
{
    int i;
    int len = 0;
    char *p;
    int isNegative = 0;
    Negative_check(&x,&isNegative,&len);
    _number_len(x,&len);
    p = (char*)malloc((len + 1) * sizeof(char));
    if (p == NULL)
    {
        return;
    }
    i = len - 1;
    if (x == INT_MIN)
    {
        p[i--] = '8';
        x = -(x /10);
        do {
            p[i--] = (x % 10) + '0';
            x /= 10;
        } while (x != 0);
    }
    do {
        p[i--] = (x % 10) + '0';
        x /= 10;
    } while (x != 0);
    if (isNegative) {
        p[0] = '-';
    }
    p[len] = '\0';
    _puts(p, counter);
    free(p);
}
