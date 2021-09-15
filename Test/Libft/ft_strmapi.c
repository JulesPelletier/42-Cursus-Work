/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:15:43 by Jules             #+#    #+#             */
/*   Updated: 2021/09/15 23:58:17 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*snew;
	unsigned int	size;

	if (!s || !f)
		return (NULL);
	size = 0;
	while (s[size])
		size++;
	snew = (char *)malloc(sizeof(char) * (size + 1));
	if (!snew)
		return (0);
	size = 0;
	while (s[size])
	{
		snew[size] = (*f)(size, s[size]);
		size++;
	}
	snew[size] = '\0';
	return (snew);
}
