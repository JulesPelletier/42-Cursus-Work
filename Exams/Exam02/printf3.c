/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:16:40 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/22 13:46:31 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_isdigt(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_converter(char c)
{
	return (c == 's' || c == 'd' || c == 'x');
}

int	count_size(int number)
{
	unsigned int	num;
	int				count;

	count = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		count++;
		num = number * -1;
	}
	else
		num = number;
	while (num > 0)
	{
		count++;
		num = num / 10;
	}
	return (count);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int num)
{
	int	n;

	if (num < 0)
	{
		ft_putchar('-');
		n = num * -1;
	}
	else
		n = num;
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + 48);
}

void	ft_putnbrhex(unsigned int num, char *base)
{
	if (num >= 16)
		ft_putnbrhex(num / 16, base);
	ft_putchar(base[num % 16]);
}

int	count_hex(unsigned int num)
{
	int				count;
	unsigned int	n;

	n = num;
	count = 0;
	if (n < 0)
		count = 8;
	else
	{
		while (n >= 16)
		{
			n = n / 16;
			count ++;
		}
		count++;
	}
	return (count);
}

int	menu(char c, va_list params)
{
	int		count;
	int		number;
	char	*str;

	count = 0;
	if (c == 'd')
	{
		number = va_arg(params, int);
		ft_putnbr(number);
		count += count_size(number);
	}
	if (c == 'x')
	{
		number = va_arg(params,unsigned int);
		ft_putnbrhex(number, "0123456789abcdef");
		count += count_hex(number);
	}
	if (c == 's')
	{
		str = va_arg(params, char *);
		ft_putstr(str);
		count += ft_strlen(str);
	}
	return (count);
}


int	ft_printf(char *str, ...)
{
	int		count;
	va_list	params;
	int		i;

	count = 0;
	i = 0;
	va_start(params, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += menu(str[i], params);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			count++;
		}
		i++;
	}
	va_end(params);
	return (count);
}

int 	main(int ac, char **av)
{
	int i;
	int val[6];

	i = 1;
	while (i < ac)
	{
		ft_printf("My tests : \n\n");
		val[0] = ft_printf("Int\t:%d \n", atoi(av[i]));
		val[1] = ft_printf("Hex\t:%x \n", atoi(av[i]));
		val[2] = ft_printf("Str\t:%s \n", av[i]);
		printf("\nReal Tests : \n\n");
		val[3] = printf("Int\t:%d\n", atoi(av[i]));
		val[4] = printf("Hex\t:%x\n", atoi(av[i]));
		val[5] = printf("Str\t:%s\n", av[i]);

		printf("Compare : \n\n");
		printf("Test Int : %d | %d\n", val[0], val[3]);
		printf("Test Hex : %d | %d\n", val[1], val[4]);
		printf("Test Str : %d | %d\n", val[2], val[5]);
		i++;
	}
}