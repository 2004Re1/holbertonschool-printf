#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
    
    
    char* hold;
    char s;
    va_list lol;
    va_start(lol, format);
    int i;
    
    
    for(i = 0 ; format[i] != '\0' ; i++)
    {
    if(format[i] != '%')
    {
        _putchar(format[i]);
        continue;
    }   
    
    else if (format[i+1] == 's')
    {
        i++;
        hold = va_arg(lol,char*);
        _puts(hold);
    }
    
    else if(format[i+1] == 'c')
    {
        i++;
        s = (char) va_arg(lol, int);
        _putchar(s);
    }
    
    else if(format[i+1] == '%')
    {
        i++;
        _putchar('%');
    }
    
    else if(format[i] == '%' && format[i+1] != '\0')
    {
        _putchar('%');
    }
    
    else if(format[i] == '%' && format[i+1] == '\0')
    {
        i++;
    }
    
    }
    va_end(lol);
    
    return (i);
    
}
