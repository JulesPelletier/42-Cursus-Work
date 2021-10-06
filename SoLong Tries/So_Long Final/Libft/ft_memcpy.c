/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:54:42 by julpelle          #+#    #+#             */
/*   Updated: 2021/07/22 08:56:53 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t		count;
	char		*dep;
	const char	*sorc;

	count = 0;
	dep = dst;
	sorc = src;
	while (count < len)
	{
		dep[count] = sorc[count];
		count++;
	}
	return (dst);
}
