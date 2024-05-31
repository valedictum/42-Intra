#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void    put_string(char *str, int   *len)
{
    if (!str)
        str = "(null)";
    while (*str)
    {
        *len += write(1, str, 1);
        str++;
    }
}

void put_digit(long long int num, int base, int *len)
{
    char    *hex = "0123456789abcdef";

    if (num < 0 && base == 10)
    {
        num = -num;
        *len += write(1, "-", 1);
    }
    if (num >= base)
        put_digit ((num / base), base, len);
    *len += write(1, &hex[num % base], 1); 
}

int ft_printf(const char *format, ... )
{
    int len = 0;

    va_list pointer;
    va_start (pointer, format);
    while (*format)
    {
        if (*format == '%' && (*(format + 1) == 's' || *(format + 1) == 'd' || *(format + 1) == 'x')) 
        {
            format++;
            if (*format == 's')
                put_string(va_arg(pointer, char *), &len);
            else if (*format == 'd')
                put_digit(va_arg(pointer, int), 10, &len);
            else if (*format == 'x')
                put_digit((unsigned long long int)va_arg(pointer, unsigned int), 16, &len);
        }
        else
            len += write (1, format, 1);
        format++;
    }
    va_end(pointer);
    return (len);
}

/*
int     main(void)
{
    int len1 = 0;
    int len2 = 0;

    len1 = ft_printf("%s\n", "toto");
    len2 = printf("%s\n", "toto");
    printf("%d\n%d\n", len1, len2);
    len1 = ft_printf("Magic %s is %d\n", "number", 42);
    len2 = printf("Magic %s is %d\n", "number", 42);
    printf("%d\n%d\n", len1, len2);
    len1 = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
    len2 = printf("Hexadecimal for %d is %x\n", 42, 42);
    printf("%d\n%d\n", len1, len2);
    return (0);
}
*/