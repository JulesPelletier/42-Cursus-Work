/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:52:01 by julpelle          #+#    #+#             */
/*   Updated: 2019/12/04 13:52:32 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;

	if (n != 0)
	{
		str = s;
		while (n != 0)
		{
			if (*str++ == c)
				return ((void *)(str - 1));
			n--;
		}
	}
	return (NULL);
}
