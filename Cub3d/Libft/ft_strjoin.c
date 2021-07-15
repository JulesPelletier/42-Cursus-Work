/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:01:05 by julpelle          #+#    #+#             */
/*   Updated: 2019/12/04 16:06:36 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result_str;
	int		index;
	int		index_bis;

	if (!s1 || !s2)
		return (NULL);
	index = 0;
	if (!(result_str = malloc(sizeof(char) *
			(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
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
