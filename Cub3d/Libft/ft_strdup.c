/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:00:44 by julpelle          #+#    #+#             */
/*   Updated: 2021/07/16 12:59:21 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*copy;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	copy = (char *)malloc(i + 1);
	if (!(copy))
		return (NULL);
	if (!(copy))
		return (NULL);
	while (j <= i)
	{
		copy[j] = src[j];
		j++;
	}
	return (copy);
}
