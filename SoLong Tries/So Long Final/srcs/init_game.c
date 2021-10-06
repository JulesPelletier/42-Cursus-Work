/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:04:33 by Jules             #+#    #+#             */
/*   Updated: 2021/09/21 14:02:59 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	init_game(t_all *all, char *file, t_list **list, t_list **error)
{
	int		res;
	char	*line;

	res = 1;
	all->params.fd	= open(file, O_RDONLY);
	if (all->params.fd < 0)
	{
		add_error(all, error, "Error opening file\n");
		return ;
	}
	printf("Bal 1 \n");
	while (res > 0)
	{
		printf("Bal 2 \n");
		res = get_next_line(all->params.fd, &line);
		printf("Bal 3 \n");
		printf("RES : %d\n", res);
		printf("Line : %s\n", line);
		if (!line[0] && res > 0)
		{
			printf("Bal 4 \n");
			add_error(all, error, "Empty line in map\n");
		}
		else if (res == 0 && !line[0])
		{
			printf("Bal 5 \n");
			break ;
		}
		printf("Bal 6 \n");
		if (detect_map_line(all, line, error))
			record_map(line, list);
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	close(all->params.fd);
}