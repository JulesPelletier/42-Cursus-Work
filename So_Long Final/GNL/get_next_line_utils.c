/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 23:19:34 by Jules             #+#    #+#             */
/*   Updated: 2021/09/15 23:38:47 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

size_t	ft_strlen_bis(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_charset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_free(char *s)
{
	free(s);
	s = NULL;
}

char	*ft_strjoin_bis(char *s1, char *s2)
{
	char			*join;
	unsigned int	size;
	unsigned int	i;
	unsigned int	f;

	if (!s1)
		s1 = ft_substr_bis("", 0, 0);
	size = ft_strlen_bis(s1) + ft_strlen_bis(s2);
	join = malloc(sizeof(char) * (size + 1));
	if (!join)
	{
		ft_free(s1);
		return (NULL);
	}
	i = 0;
	f = 0;
	while (s1[i])
		join[f++] = s1[i++];
	i = 0;
	while (s2[i])
		join[f++] = s2[i++];
	join[f] = '\0';
	if (s1)
		ft_free(s1);
	return (join);
}

char	*ft_substr_bis(char *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	if (!s)
		s = "";
	if (start > ft_strlen_bis(s))
		len = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
