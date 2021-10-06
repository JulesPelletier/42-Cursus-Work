/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:51:13 by julpelle          #+#    #+#             */
/*   Updated: 2021/09/15 23:20:57 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	check_size(char *str, char *charset)
{
	int	size;

	size = 0;
	while (*str)
	{
		while (*str && check_charset(*str, charset) != -1)
			str++;
		if (*str && check_charset(*str, charset) == -1)
		{
			size++;
			while (*str && check_charset(*str, charset) == -1)
				str++;
		}
	}
	return (size);
}

char	*create_string(char *str, char *charset)
{
	int		z;
	char	*split;
	int		x;

	x = 0;
	z = 0;
	while (str[x] && check_charset(str[x], charset) == -1)
		x++;
	split = (char *)malloc(sizeof(char) * (x + 1));
	if (!split)
		return (NULL);
	x = 0;
	while (str[x] && check_charset(str[x], charset) != -1)
		x++;
	while (str[x] && check_charset(str[x], charset) == -1)
	{
		split[z] = str[x];
		z++;
		x++;
	}
	split[z] = '\0';
	return (split);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**split_tab;

	split_tab = (char **)malloc(sizeof(char *)
			*(check_size(str, charset) + 1));
	if (!split_tab)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && check_charset(*str, charset) != -1)
			str++;
		if (*str && check_charset(*str, charset) == -1)
		{
			split_tab[i] = create_string(str, charset);
			i++;
			while (*str && check_charset(*str, charset) == -1)
				str++;
		}
	}
	split_tab[i] = NULL;
	return (split_tab);
}
