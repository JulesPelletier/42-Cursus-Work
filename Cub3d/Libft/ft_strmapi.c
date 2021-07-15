/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:03:24 by julpelle          #+#    #+#             */
/*   Updated: 2019/12/04 14:04:04 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str_result;
	unsigned int		i;
	int					len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s) + 1;
	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(str_result = (char *)malloc(sizeof(char) * (len_s))))
		return (NULL);
	while (s[i])
	{
		str_result[i] = f(i, s[i]);
		i++;
	}
	str_result[i] = '\0';
	return (str_result);
}
