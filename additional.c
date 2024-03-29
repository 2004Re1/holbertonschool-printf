#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"
/**
 * _putchar - is function.
 *@c: is variable.
 */

extern unsigned int write_length;
int  _putchar(char c) 
{
	write_length++;
	return(write(1, &c, 1));
}
/**
 *_puts - is func.
 *@str: is string
 */
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

void _printnum(int x)
{
    int temp;
    int i;
    int len = 0;
    char *p;
    
    int isNegative = 0;
    if (x < 0) {
        isNegative = 1;
        len++;
        if (x != INT_MIN)
        {
            x = -x;
            
        }
    }
    temp = x;
    do {
        len++;
        temp /= 10;
    } while (temp != 0);
    p = (char*)malloc((len + 1) * sizeof(char)); 
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
    printf("%s", p);
    free(p);
}

