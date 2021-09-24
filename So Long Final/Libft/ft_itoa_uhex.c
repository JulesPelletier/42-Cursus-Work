/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:12:06 by Jules             #+#    #+#             */
/*   Updated: 2021/09/15 23:55:31 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*alloc_itoa_uhex(unsigned int n, int size, int sign)
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
		if (n % 16 <= 9)
			itoa[size] = n % 16 + '0';
		else
			itoa[size] = n % 16 - 10 + 'a';
		n = n / 16;
		size--;
	}
	if (sign == 1)
		itoa[size] = '-';
	return (itoa);
}

int	get_size_uhex(unsigned int n)
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
		n /= 16;
		size++;
	}
	return (size);
}

char	*ft_itoa_uhex(unsigned int n)
{
	unsigned int	nbx;
	int				size;
	int				sign;
	char			*itoa;

	size = get_size_uhex(n);
	sign = 0;
	if (n < 0)
	{
		nbx = (unsigned int)(-1 * n);
		sign++;
	}
	else
		nbx = (unsigned int)n;
	itoa = alloc_itoa_uhex(nbx, size, sign);
	return (itoa);
}
