/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 21:12:43 by julpelle          #+#    #+#             */
/*   Updated: 2021/07/22 08:56:57 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				count;
	unsigned char		*dep;

	count = 0;
	dep = malloc(sizeof(unsigned char *) * len);
	if (!(dep))
		return (0);
	while (count < len)
	{
		dep[count] = *(unsigned char *)src;
		count++;
		src++;
	}
	count = 0;
	while (count < len)
	{
		*(unsigned char *)dst = dep[count];
		dst++;
		count++;
	}
	return (dst - count);
}
