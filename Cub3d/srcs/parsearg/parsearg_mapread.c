/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg_mapread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:43:02 by Jules             #+#    #+#             */
/*   Updated: 2021/07/16 14:21:49 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	ft_parsearg_mapread_sizemapline(char *line)
{
	int	size;

	size = 0;
	while (*line)
	{
		size++;
		line++;
	}
	return (size);
}

char	*ft_parsearg_mapread_mapline(char *line)
{
	char	*str;
	int		i;
	int		j;
	int		size;

	str = NULL;
	size = ft_parsearg_mapread_sizemapline(line);
	str = malloc(sizeof(char) * (size + 2));
	if (!(str))
		return (NULL);
	i = 0;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\n';
	j++;
	str[j] = '\0';
	return (str);
}

void	ft_parsearg_mapread_strmapupdate(t_st *st, char *line)
{
	char		*tmp1;
	char		*tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
	tmp1 = ft_parsearg_mapread_mapline(line);
	if ((tmp1 == NULL))
		ft_error(st, -14);
	if ((int)ft_strlen(tmp1) - 1 > st->maps.sizemapx)
		st->maps.sizemapx = (int)ft_strlen(tmp1) - 1;
	tmp2 = ft_strjoin(st->pars.strmap, tmp1);
	if ((tmp2 == NULL))
	{
		free(tmp1);
		ft_error(st, -14);
	}
	free(tmp1);
	free(st->pars.strmap);
	st->pars.strmap = tmp2;
}

void	ft_parsearg_mapread_strmapinit(t_st *st, char *line)
{
	char		*tmp1;

	tmp1 = NULL;
	tmp1 = ft_parsearg_mapread_mapline(line);
	if ((tmp1 == NULL))
		ft_error(st, -14);
	st->pars.strmap = tmp1;
	st->maps.sizemapx = (int)ft_strlen(st->pars.strmap) - 1;
}

void	ft_parsearg_mapread(t_st *st, char *line)
{
	if (st->pars.strmap == NULL)
		ft_parsearg_mapread_strmapinit(st, line);
	else
		ft_parsearg_mapread_strmapupdate(st, line);
	if (st->pars.retgnl == 0)
		ft_parsearg_mapinit(st);
}
