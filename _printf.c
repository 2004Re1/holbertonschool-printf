#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
extern unsigned int write_length;
/**
 *_printf - is.
 *@format: is string.
 *@...:is numbers variables.
 */
int _printf(const char *format, ...)
{
    int i;
    int list;
    char* hold;
    char s;
    va_list lol;
    va_start(lol, format);
    write_length = 0;
    
    for(i = 0 ; format[i] != '\0' ; i++)
    {
    if(format[i] != '%')
    {
        _putchar(format[i]);
        continue;
   
    }

    else if (format[i+1] == 'd' || format[i+1] == 'i')
    {
        i++;
        list = va_arg(lol, int);
        _printnum(list);
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
        char c;
	    c = format[++i];
	    if (c == 0)
	        goto END_ZONE;
        i++;
    }
    
    }
    va_end(lol);
    END_ZONE:
    if (write_length == 0) {
        return -1;
    }
    
    return (write_length);
    
}
