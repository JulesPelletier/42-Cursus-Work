/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 01:14:05 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/05 14:32:36 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str, char const *to_find, size_t len)
{
	size_t	j;

	j = 0;
	if (to_find[0] == 0)
		return ((char *)str);
	j = ft_strlen(to_find);
	while (*str && len >= j)
	{
		if (*str == *to_find && ft_memcmp(str, to_find, j) == 0)
			return ((char *)str);
		str++;
		len--;
	}
	return (NULL);
}
