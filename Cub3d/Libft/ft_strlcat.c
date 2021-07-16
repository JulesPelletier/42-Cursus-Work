/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:02:06 by julpelle          #+#    #+#             */
/*   Updated: 2021/07/16 13:05:58 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	len_src;

	len = 0;
	len_src = ft_strlen((char *)src);
	while (dest[len] && len < size)
		len = len + 1;
	i = len;
	while (src[len - i] && len + 1 < size)
	{
		dest[len] = src[len - i];
		len = len + 1;
	}
	if (i < size)
		dest[len] = '\0';
	return (len_src + i);
}
