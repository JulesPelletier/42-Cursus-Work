/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 21:22:38 by julpelle          #+#    #+#             */
/*   Updated: 2021/07/22 08:57:47 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		counts1;
	int		counts2;
	char	*ptr;

	counts1 = 1;
	counts2 = 1;
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		counts1 = ft_strlen(s1);
	if (s2)
		counts2 = ft_strlen(s2);
	if (s1 && !s2)
		ptr = ft_substr(s1, 0, counts1);
	if (s2 && !s1)
		ptr = ft_substr(s2, 0, counts2);
	if (!s1 || !s2)
		return (ptr);
	ptr = malloc(sizeof(char) * (counts1 + counts2 + 1));
	if (!(ptr))
		return (NULL);
	ft_strlcpy(ptr, s1, counts1 + counts2 + 1);
	ft_strlcat(ptr, s2, counts2 + counts1 + 1);
	return (ptr);
}
