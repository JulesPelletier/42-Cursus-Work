/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:13:59 by Jules             #+#    #+#             */
/*   Updated: 2021/09/15 23:57:05 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*head;

	if (!dest && !src)
		return ((void *)0);
	head = dest;
	while (n > 0)
	{
		*((char *)head) = *((char *)src);
		head++;
		src++;
		n--;
	}
	return (dest);
}
