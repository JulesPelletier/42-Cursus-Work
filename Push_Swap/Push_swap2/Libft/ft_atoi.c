/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:38:09 by julpelle          #+#    #+#             */
/*   Updated: 2021/07/22 08:55:36 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	count;
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	count = 0;
	while (str[count] == '\t' || str[count] == '\n'
		|| str[count] == '\v' || str[count] == '\r'
		|| str[count] == '\f' || str[count] == ' ')
		count++;
	if (str[count] == '-')
		sign = -1;
	if (str[count] == '+' || str[count] == '-')
		count++;
	while (str[count] != '\0')
	{
		if (str[count] >= '0' && str[count] <= '9')
			res = (res * 10) + str[count] - '0';
		if (!(str[count] >= '0' && str[count] <= '9'))
			return (res * sign);
		count++;
	}
	return (res * sign);
}
