/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:11:04 by Jules             #+#    #+#             */
/*   Updated: 2021/09/15 23:54:51 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int nmemb, int size)
{
	void	*array;

	array = (void *)malloc(nmemb * size);
	if (!array)
		return (0);
	ft_bzero(array, (size * nmemb));
	return ((void *)array);
}
