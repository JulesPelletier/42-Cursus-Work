/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:51:03 by julpelle          #+#    #+#             */
/*   Updated: 2021/07/16 12:50:10 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*d;
	const char	*s;

	if (n == 0)
		return (NULL);
	if (n != 0)
	{
		d = dst;
		s = src;
		while (n != 0)
		{
			*d++ = *s++;
			if (*d++ == (char)c)
				return ((void *)d);
			else
				n--;
		}
	}
	return (NULL);
}
