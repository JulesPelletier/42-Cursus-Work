/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:16:32 by Jules             #+#    #+#             */
/*   Updated: 2021/09/15 23:58:41 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, char const *set)
{
	size_t	x;
	size_t	y;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup((char *)s1));
	x = 0;
	y = ft_strlen(s1) - 1;
	while (s1[x] && ft_strchr(set, s1[x]))
		x++;
	if (!s1[x])
		return (ft_strdup(""));
	while (s1[y] && ft_strchr(set, s1[y]))
		y--;
	return (ft_substr(s1, x, y - x + 1));
}
