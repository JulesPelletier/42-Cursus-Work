/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:12:06 by Jules             #+#    #+#             */
/*   Updated: 2021/09/15 23:55:36 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*alloc_itoa(unsigned int n, int size, int sign)
{
	char	*itoa;

	itoa = (char *)malloc(sizeof(char) * (size + 1));
	if (!itoa)
		return (0);
	itoa[size] = '\0';
	size--;
	if (n == 0)
		itoa[size] = '0';
	while (n > 0)
	{
		itoa[size] = n % 10 + 48;
		size--;
		n /= 10;
	}
	if (sign == 1)
		itoa[size] = '-';
	return (itoa);
}

int	get_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
	{
		size = 1;
		return (size);
	}
	if (n < 0)
		size++;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	unsigned int	nbx;
	int				size;
	int				sign;
	char			*itoa;

	size = get_size(n);
	sign = 0;
	if (n < 0)
	{
		nbx = (unsigned int)(-1 * n);
		sign++;
	}
	else
		nbx = (unsigned int)n;
	itoa = alloc_itoa(nbx, size, sign);
	return (itoa);
}
