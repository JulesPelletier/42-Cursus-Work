/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 19:02:56 by Jules             #+#    #+#             */
/*   Updated: 2021/09/16 00:19:21 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	map_parsing(t_input *args, t_all *all)
{
	int	res;

	args->index = "1RNSWEXFC";
	(args->map) = ft_strdup("");
	res = get_next_line(args->fd, &(args->line));
	while (res != 0)
	{
		if (res == -1)
			return (-1);
		args->tracker = 0;
		while (args->line[args->tracker] == ' ')
			args->tracker++;
		args->index_i = check_charset(args->line[args->tracker], args->index);
		if (args->index_i == 0)
			create_map(args);
		ft_free(args->line);
		res = get_next_line(args->fd, &(args->line));
	}
	create_map(args);
	free(args->line);
	args->matrix = ft_split(args->map, "x");
	check_map(all);
	ft_free(args->map);
	return (1);
}
