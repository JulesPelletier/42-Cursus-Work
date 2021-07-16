/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:07:47 by julpelle          #+#    #+#             */
/*   Updated: 2021/07/16 14:57:05 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mall(int n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * n);
	if (str == NULL)
		return (NULL);
	return (str);
}

size_t	ternary(size_t len, size_t lalen, unsigned int start)
{
	if (lalen - start < len)
		return (lalen - start);
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		cpy;
	size_t	lalen;

	if (s == NULL || start < 0)
		return (NULL);
	lalen = ft_strlen((char *)s);
	if (start >= lalen)
		len = 0;
	else
		len = ternary(len, lalen, start);
	res = ft_mall(len + 1);
	if (res == 0)
		return (NULL);
	cpy = 0;
	while (len)
	{
		res[cpy] = s[start];
		cpy++;
		start++;
		len--;
	}
	res[cpy] = '\0';
	return (res);
}
