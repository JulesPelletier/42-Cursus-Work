/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:12:15 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/08 14:28:16 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr_hexa(unsigned long int n, char *base)
{
    char    c;

    if (n >= 16)
        ft_putnbr_hexa(n / 16, base);
    c = base[n % 16];
    ft_putchar(c);
}

void    ft_putnbr(int n)
{
    int nbr;
    
    if (n < 0)
        nbr = nbr * -1;
    else
        nbr = n;
    if (n / 10)
        ft_putnbr(nbr / 10);
    ft_putchar((nbr % 10) + 48);
}

int main(int ac, char **av)
{
    int i;

    i = 1;
    while (i < ac)
    {
        ft_putnbr_hexa(atoi(av[i]), "0123456789abcdef");
        ft_putchar('\n');
        printf("%10.1x\n", atoi(av[i]));
        printf("%4.2d\n", atoi(av[i]));
        ft_putnbr(atoi(av[i]));
        ft_putchar('\n');
        printf("%10.4s\n", av[i]);
        i++;
    }
    return (0);
}