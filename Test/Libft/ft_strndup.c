/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:15:56 by Jules             #+#    #+#             */
/*   Updated: 2021/09/15 23:58:27 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *temp, int n)
{
	char	*line;
	int		i;

	line = (char *)malloc(sizeof(char) * (n + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < n)
	{
		line[i] = temp[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
