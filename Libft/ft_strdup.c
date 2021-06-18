/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:00:44 by julpelle          #+#    #+#             */
/*   Updated: 2019/12/04 14:00:57 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*copy;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (!(copy = (char*)malloc(i + 1)))
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
