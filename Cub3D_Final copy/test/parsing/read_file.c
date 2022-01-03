/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:36:54 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/02 17:13:08 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	read_file(t_all *all, char *file)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_exit("Error : failed to open map\n");
	all->mlx_ptr = mlx_init();
	if (!all->mlx_ptr)
		free_parsing(all, NULL);
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (line)
			parse_line(all, line, ret);
		free(line);
		if (ret == 0)
			break ;
		if (ret == -1)
		{
			close(fd);
			free_all(all);
			ft_exit("Error : reading failed\n");
		}
	}
	close(fd);
}