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
    if (format[i+1] == 'd'|| format[i+1] == 'i') 
    {
	    int x = va_arg(lol,int);
	    int len = 0;
	    char *p;
	
	    int isNegative = 0;
	    if (x < 0) {
	        isNegative = 1;
	        x = -x;
	        len++;
	    }
	
	    int temp = x;
	    do {
	        len++;
	        temp /= 10;
	    } while (temp != 0);
	
	   
	    p = (char*)malloc((len + 1) * sizeof(char)); // +1 for null terminator
	
	
	    int i = len - 1;
	    do {
	        p[i--] = (x % 10) + '0';
	        x /= 10;
	    } while (x != 0);
	
	
	    if (isNegative)
	        p[0] = '-';
	
	 
	    p[len] = '\0';
	
	    _puts(p);
	    free(p);
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
