/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:16:03 by Jules             #+#    #+#             */
/*   Updated: 2021/09/15 23:58:32 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	f;

	i = 0;
	if (little[i] == '\0' || !little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		f = 0;
		while (big[i + f] == little[f] && i + f < len)
		{
			if (little[f + 1] == '\0')
				return ((char *)&big[i]);
			f++;
		}
		i++;
	}
	return (NULL);
}
