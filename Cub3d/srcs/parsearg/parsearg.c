/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:30:54 by Jules             #+#    #+#             */
/*   Updated: 2021/07/09 15:29:21 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_parsearg_checkarg(t_st *st, char *arg)
{
	int	size;

	size = ft_strlen(arg);
	if (arg[size - 4] != '.' || arg[size - 3] != 'c' || arg[size - 2] != 'u'
			|| arg[size - 1] != 'b')
		ft_error(st, -3);
}

void	ft_parsearg(t_st *st, char *arg)
{
	int		fd;
	char	*line;

	ft_parsearg_checkarg(st, arg);
	if ((fd = open(arg, O_RDONLY)) == -1)
		ft_error(st, -4);
	st->pars.retgnl = 1;
	while (st->pars.retgnl)
	{
		st->pars.retgnl = get_next_line(fd, &line);
		if (line == NULL)
			ft_error(st, -5);
		st->pars.line = line;
		ft_parsearg_fileread(st, st->pars.line);
		free(st->pars.line);
		st->pars.line = NULL;
	}
	close(fd);
}
