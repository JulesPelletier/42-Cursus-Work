/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:36:54 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/02 22:34:34 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_iswhitespace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

void	check_limits(t_info *info, char **map, int x, int y)
{
	if ((x >= ft_strlen(map[y - 1]) || x >= ft_strlen(map[y + 1])) && \
		map[y][x] == '_')
	{
		free(map);
		parsing_error(NULL, info, "map open\n");
	}
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

unsigned char	get_color(char *line, t_info *info, int i)
{
	int	color;

	color = ft_atoi(line + i);
	if (color < 0 || color > 255)
		parsing_error(line, info, "color values must be 0-255\n");
	return (color);
}

void	free_texture(void *mlx_ptr, t_texture *texture)
{
	if (texture)
	{
		if (texture->texture)
			mlx_destroy_image(mlx_ptr, texture->texture);
		free(texture);
	}
}

t_texture	*get_texture(char *file, t_info *info)
{
	int			i;
	int			data[3];
	t_texture	*img;

	img = ft_calloc(1, sizeof(t_texture));
	if (!img)
		parsing_error(file, info, "problem allocating texture struct\n");
	i = 2;
	while (file[i] && ft_iswhitespace(file[i]))
		i++;
	img->texture = mlx_xpm_file_to_image(info->mlx_ptr, file + i, \
	&img->width, &img->height);
	if (img->texture)
	{
		data[0] = 0;
		data[1] = 0;
		data[2] = 0;
		img->data = mlx_get_data_addr(img->texture, &data[0], &data[1], \
		&data[2]);
	}
	return (img);
}