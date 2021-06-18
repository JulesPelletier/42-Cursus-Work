/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:54:03 by julpelle          #+#    #+#             */
/*   Updated: 2019/12/04 13:54:57 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (len == 0)
		return ((void *)dst);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
		return ((void *)dst);
	}
	if (!dst && !src)
		return ((void *)0);
	else
	{
		s = s + (len - 1);
		d = d + (len - 1);
		while (len--)
			*d-- = *s--;
		return ((void *)dst);
	}
	return ((void *)0);
}
