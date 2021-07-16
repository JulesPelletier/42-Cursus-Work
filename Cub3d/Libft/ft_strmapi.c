/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:03:24 by julpelle          #+#    #+#             */
/*   Updated: 2021/07/16 14:57:00 by julpelle         ###   ########.fr       */
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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str_result;
	unsigned int		i;
	int					len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s) + 1;
	i = 0;
	if (!s || !f)
		return (NULL);
	str_result = ft_mall(len_s);
	while (s[i])
	{
		str_result[i] = f(i, s[i]);
		i++;
	}
	str_result[i] = '\0';
	return (str_result);
}
