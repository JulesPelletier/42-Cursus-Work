/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:01:05 by julpelle          #+#    #+#             */
/*   Updated: 2021/07/16 13:05:23 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mall(int n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * n)
		if (str == NULL)
		return (NULL);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result_str;
	int		index;
	int		index_bis;

	if (!s1 || !s2)
		return (NULL);
	index = 0;
	result_str = ft_mall(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (index < (int)ft_strlen(s1))
	{
		result_str[index] = s1[index];
		index++;
	}
	index_bis = 0;
	while (index < (int)(ft_strlen(s1) + ft_strlen(s2)))
	{
		result_str[index] = s2[index_bis];
		index++;
		index_bis++;
	}
	result_str[index] = '\0';
	return (result_str);
}
