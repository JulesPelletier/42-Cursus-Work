/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:43:35 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/02 22:39:59 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_info(t_info *info)
{
	if (info->map_ptr)
		ft_lstclear(&(info->map_ptr), &free);
	if (info->map)
		free_map(info->map);
	if (info->mlx_ptr)
	{
		if (info->window_ptr)
			//mlx_destroy_window(info->mlx_ptr, info->window_ptr);
		if (info->image)
			//mlx_destroy_image(info->mlx_ptr, info->image);
		free_texture(info->mlx_ptr, info->no_texture);
		free_texture(info->mlx_ptr, info->so_texture);
		free_texture(info->mlx_ptr, info->ea_texture);
		free_texture(info->mlx_ptr, info->we_texture);
		//mlx_destroy_display(info->mlx_ptr);
		free(info->mlx_ptr);
	}
	if (info->player)
		free(info->player);
	if (info->rays)
		free(info->rays);
	free(info);
}

void	parsing_error(char *line, t_info *info, char *error)
{
	if (line)
		free(line);
	free_info(info);
	ft_putstr_fd("Error\n", 2);
	if (error)
		ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}

void	check_parsing(t_info *info)
{
	if (!info->no_texture || !info->so_texture || \
		!info->we_texture || !info->ea_texture)
		parsing_error(NULL, info, "problem while creating texture struct\n");
	if (!info->no_texture->texture || !info->so_texture->texture || \
		!info->we_texture->texture || !info->ea_texture->texture)
		parsing_error(NULL, info, "texture invalid or not attributed\n");
	if (!info->map_ptr)
		parsing_error(NULL, info, "map invalid or not attributed\n");
	check_map(info);
}

void	handle_info_line(char *line, t_info *info)
{
	if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
		parsing_text(line, info);
	if (*line == 'F' || *line == 'C')
		parsing_color(line, info);
}

void	handle_map_line(char *line, t_info *info)
{
	t_list	*new;

	new = ft_lstnew(ft_strdup(line));
	if (!new || !(new->content))
		parsing_error(line, info, "error allocating the map\n");
	ft_lstadd_back(&(info->map_ptr), new);
}
