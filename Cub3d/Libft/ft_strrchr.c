/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:06:06 by julpelle          #+#    #+#             */
/*   Updated: 2019/12/04 15:48:06 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*str;
	const char		*p;
	unsigned char	c_bis;

	str = NULL;
	c_bis = (unsigned char)c;
	p = ft_strchr(s, c);
	if (c == '\0')
		return (ft_strchr(s, '\0'));
	while (p != NULL)
	{
		str = p;
		s = p + 1;
		p = ft_strchr(s, c);
	}
	return ((char *)str);
}
