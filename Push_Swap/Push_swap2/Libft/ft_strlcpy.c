/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 21:48:47 by julpelle          #+#    #+#             */
/*   Updated: 2021/07/22 08:57:59 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	countsrc;
	int	countdst;

	countdst = 0;
	countsrc = ft_strlen(src);
	if ((int)dstsize == 0)
		return (countsrc);
	while (countdst < (int)dstsize - 1 && countdst < countsrc)
	{
		dst[countdst] = src[countdst];
		countdst++;
	}
	dst[countdst] = '\0';
	return (countsrc);
}
