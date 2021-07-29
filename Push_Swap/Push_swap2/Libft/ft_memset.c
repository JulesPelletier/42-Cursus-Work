/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 07:15:07 by julpelle          #+#    #+#             */
/*   Updated: 2021/07/22 08:57:04 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int val, size_t len)
{
	size_t	count;

	count = 0;
	while (count < len)
	{
		*(unsigned char *)(ptr + count) = val;
		count++;
	}
	return (ptr);
}
