#include "../includes/lib_printf.h"

void     ft_display_c(va_list params)
{
    char    c;

    c = va_arg(params, int);
    ft_putchar(c);
}

void     ft_display_s(va_list params)
{
    char    *s;

    s = va_arg(params, char *);
    ft_putstr(s);
}

void     ft_display_id(va_list params)
{
    int     i;

    i = va_arg(params, int);
    ft_putnbr(i);
}

void     ft_display_u(va_list params)
{
    unsigned int     i;

    i = va_arg(params, unsigned);
    ft_putnbr_unsigned(i);
}

void     ft_display_p(va_list params)
{
    void    *i;
    void    **ptr;
    
    i = va_arg(params, void*);
    ptr = &i;
    //printf("I : %s\nAdresse de I : %p\n", i, ptr);
    ft_putstr((char *)ptr);
}

void     ft_display_x(va_list params)
{
    ft_putnbr_base(va_arg(params, int), "0123456789abcdef");
}

void     ft_display_X(va_list params)
{
    ft_putnbr_base(va_arg(params, int), "0123456789ABCDEF");
}

int     ft_is_converter(char c)
{
    if (c == 'c' || c == 's' || c == 'p' || c == 'd'
        || c == 'i' || c == 'u')
        return (1);
    else
        return (0);
}