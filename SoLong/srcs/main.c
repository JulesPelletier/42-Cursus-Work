/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:29:45 by julpelle          #+#    #+#             */
/*   Updated: 2021/10/06 19:15:52 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static void	read_file(t_all *all, char *file, t_list **list, t_list **error)
{
	int		res;
	char	*line;

	res = 1;
	all->fd = open(file, O_RDONLY);
	if (all->fd < 0)
	{
		add_error(all, error, "Error open file\n");
		return ;
	}
	while (res > 0)
	{
		res = get_next_line(all->fd, &line);
		if (!line[0] && res > 0)
			add_error(all, error, "\\n in map\n");
		else if (res == 0 && !line[0])
			break ;
		if (check_line(line, error, all))
			get_map(line, list);
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	close(all->fd);
}

int	main(int argc, char **argv)
{
	t_all		all;
	t_list		*list;
	t_list		*error;

	list = NULL;
	error = NULL;
	init_all(&all);
	if (!check_args(&all, argc, argv[1], &error))
	{
		read_file(&all, argv[1], &list, &error);
		if (!error)
			count_grid(&all, list, &error);
		if (!error)
		{
			ft_lstclear(&list, &free_map);
			game_loop(&all);
		}
	}
	if (error)
		show_error(error);
	free_global(list, all, error);
	return (0);
}
