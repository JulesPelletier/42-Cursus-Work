/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:17:20 by julpelle          #+#    #+#             */
/*   Updated: 2021/08/31 15:47:30 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long	res;
	int				neg;
	int				pos;

	pos = 0;
	while (str[pos] == '\t' || str[pos] == '\n' || str[pos] == '\v'
			|| str[pos] == '\f' || str[pos] == '\r' || str[pos] == ' ')
		pos++;
	neg = 1;
	if (str[pos] == '+' || str[pos] == '-')
	{
		if (str[pos] == '-')
			neg++;
		pos++;
	}
	res = 0;
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		res = res * 10;
		res = res + str[pos] - 48;
		pos++;
	}
	if (neg % 2 == 0)
		return (-res);
	return (res);
}
