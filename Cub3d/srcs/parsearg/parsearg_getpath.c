/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg_getpath.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:37:53 by Jules             #+#    #+#             */
/*   Updated: 2021/07/16 13:53:53 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

char	*ft_parsearg_getpath(t_st *st, char *line)
{
	char	*str;
	int		i;

	str = NULL;
	while (*line == ' ')
		line++;
	if (*line == '\0')
		ft_error(st, -12);
	str = ft_strdup(line);
	if (str == NULL)
		ft_error(st, -14);
	i = 0;
	while (*(str + i) != ' ' && *(str + i) != '\0')
		i++;
	*(str + i) = '\0';
	while (*line != ' ' && *line != '\0')
		line++;
	while (*line == ' ')
		line++;
	if (*line != '\0')
		ft_error(st, -13);
	return (str);
}
