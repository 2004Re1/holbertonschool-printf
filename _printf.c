#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 *_printf - is.
 *@format: is string.
 *@...:is numbers variables.
 */
void checker (const char *format,va_list *lol, int *counter)
{
    int i;
    int list;
    char* hold;
    char s;
    for(i = 0 ; format[i] != '\0' ; i++)
    {
    if(format[i] != '%')
    {
        _putchar(format[i],counter);
        continue;
    }
    else if (format[i+1] == 'd' || format[i+1] == 'i')
    {
        i++;
        list = va_arg(*lol, int);
        _printnum(list,counter);
    }
    else if (format[i+1] == 's')
    {
        i++;
        _puts(va_arg(*lol,char*),counter);
    }
    else if(format[i+1] == 'c')
    {
        i++;
        _putchar((char)va_arg(*lol, int),counter);
    }
    else if(format[i+1] == '%')
    {
        i++;
        _putchar('%',counter);
    }
    else if(format[i] == '%' && format[i+1] != '\0')
    {
        _putchar('%',counter);
    }
    
    else if(format[i] == '%' && format[i+1] == '\0')
    {
        i++;
    }
    }
}


int _printf(const char *format, ...)
{
    int counter_org;
   

    va_list lol;
    va_start(lol, format);
    checker(format,&lol,&counter_org);

    va_end(lol);
    return (counter_org);
}
