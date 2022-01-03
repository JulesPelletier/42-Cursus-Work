/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:43:35 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/02 22:30:52 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	error_map_name(char *map, t_info *info)
{
	int	size;

	if (!info)
	{
		ft_putstr_fd("Error\nMemory allocation error\n", 2);
		exit(EXIT_FAILURE);
	}
	size = ft_strlen(map);
	if (size < 4 || ft_strncmp(map + (size - 4), ".cub", 4))
	{
		ft_putstr_fd("Error\nMap format is incorrect\n", 2);
		free_info(info);
		exit(EXIT_FAILURE);
	}
}

void	handle_line(char *line, t_info *info, int ret)
{
	if (info->map_start && *line == '\0' && ret == 1)
		parsing_error(line, info, "map should end the config file\n");
	if (*line == '\0')
		return ;
	if (info->map_start && (!ft_isdigit(*line) && *line != 32))
		parsing_error(line, info, "map should end the config file\n");
	if (ft_isdigit(*line) || *line == 32)
	{
		info->map_start = 1;
		handle_map_line(line, info);
	}
	else
		handle_info_line(line, info);
}

void	read_file(int fd, t_info *info)
{
	int		ret;
	char	*line;

	info->mlx_ptr = mlx_init();
	if (!info->mlx_ptr)
		parsing_error(NULL, info, "problem initalizing the mlx\n");
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (line)
			handle_line(line, info, ret);
		free(line);
		if (ret == 0)
			break ;
		if (ret == -1)
		{
			ft_putstr_fd("Error\nreading error\n", 2);
			close(fd);
			free_info(info);
			exit(EXIT_FAILURE);
		}
	}
}

void	open_file(char *map, t_info *info)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(map, 2);
		ft_putstr_fd(" : ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		free_info(info);
		exit(EXIT_FAILURE);
	}
	read_file(fd, info);
	close(fd);
}

t_info	*ft_parsing(char *map)
{
	t_info	*info;

	info = ft_calloc(1, sizeof(t_info));
	error_map_name(map, info);
	open_file(map, info);
	check_parsing(info);
	return (info);
}
