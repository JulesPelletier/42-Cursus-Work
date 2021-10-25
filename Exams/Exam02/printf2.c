/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:32:47 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/18 15:32:07 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct  s_flag
{
    int i;
    int ret;
}               t_flag;

void    init_flags(t_flag *flags)
{
    flags->i = 0;
    flags->ret = 0;
}

void    ft_putchar(char c, t_flag *flags)
{
    write(1, &c, 1);
    flags->ret++;
}

void    ft_putstr(char *str, t_flag *flags)
{
    int i;

    i = 0;
    if (!str)
        ;
    while (str[i])
    {
        ft_putchar(str[i], flags);
        i++;
    }
}

void    ft_putnbr(int nb, t_flag *flags)
{
    int n;

    if (nb < 0)
    {
        ft_putchar('-', flags);
        n = nb * -1;
    }
    else
        n = nb;
    if (n >= 10)
        ft_putnbr(n / 10, flags);
    ft_putchar((n % 10) + 48, flags);
}

void    ft_putnbrhex(unsigned int nb, char *base, t_flag *flags)
{
    if (nb >= 16)
        ft_putnbrhex(nb / 16, base, flags);
    ft_putchar(base[nb % 16], flags);
}

int ft_display_s(char *str, int pos, t_flag *flags)
{
    ft_putstr(str, flags);
    return (pos + 1);
}

int ft_display_d(int n, int pos, t_flag *flags)
{
    ft_putnbr(n, flags);
    return (pos + 1);
}

int ft_display_x(int n, int pos, t_flag *flags)
{
    ft_putnbrhex(n, "0123456789abcdef", flags);
    return (pos + 1);
}

int dispatch(char *str, int i, va_list params, t_flag *flags)
{
    if (str[i] == '%')
    {
        i++;
        if (str[i] == 'd')
            return (ft_display_d(va_arg(params, int), i, flags));
        if (str[i] == 's')
            return (ft_display_s(va_arg(params, char *), i, flags));
        if (str[i] == 'x')
            return (ft_display_x(va_arg(params, int), i, flags));
    }
    return (-1);
}

int ft_parse(const char *str, va_list params, t_flag *flags)
{
    int i;

    i = 0;
    flags->ret = flags->ret + 5;
    while (str[i])
    {
        if (str[i] == '%')
            i = dispatch((char *)str, i, params, flags);
        while (str[i] && str[i] != '%')
        {
            ft_putchar(str[i], flags);
            i++;
        }
    }
    return (flags->ret);
}

int ft_printf(const char *str, ...)
{
    va_list params;
    int     ret;
    t_flag  flags;

    init_flags(&flags);
    va_start(params, str);
    ret = ft_parse(str, params, &flags);
    va_end(params);
    return (ret);
}

int main(int ac, char **av)
{
    int i;

    i = 1;
    while (i < ac)
    {
        int a, b, c, d, e, f;
        a = ft_printf("Int : %d\n", atoi(av[i]));
        b = ft_printf("Str : %s\n", av[i]);
        c = ft_printf("Hex : %x\n", atoi(av[i]));
        d = printf("Real Int : %d\n", atoi(av[i]));
        e = printf("Real Str : %s\n", av[i]);
        f = printf("Real Hex : %x\n", atoi(av[i]));
        printf("[%d] : [%d]\n", a, d);
        printf("[%d] : [%d]\n", b, e);
        printf("[%d] : [%d]\n", c, f);
        i++;
    }
    return (0);
}