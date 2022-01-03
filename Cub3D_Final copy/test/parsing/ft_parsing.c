/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:32:46 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/02 22:10:57 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
void	parse_map(t_all *all, char *line)
{
	if (*line == 'N')
}
*/

t_texture	*get_tex(t_all *all, t_texture *tex, char *line)
{
	t_texture	*text;
	int			i;
	int			data[3];

	if (tex)
		free_tex(all->mlx_ptr, tex);
	text = ft_calloc(1, sizeof(t_texture));
	if (!text)
		free_parsing(all, line);
	i = 2;
	while (line[i] && ft_iswhite_space(line[i]))
		i++;
	text->texture = mlx_xpm_file_to_image(all->mlx_ptr, line + i, &text->width, &text->height);	
	if (text->texture)
	{
		data[0] = 0;
		data[1] = 0;
		data[2] = 0;
		text->data = mlx_get_data_addr(text->texture, &data[0], &data[1], &data[2]);
	}
	return (text);
}

void	ft_color(unsigned char color[4], unsigned char tab[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		color[i] = tab[i];
		i++;
	}
	color[3] = 0;
}

void	parse_res(t_all *all, char *line)
{
	int				i;
	unsigned char	tab[3];

	i = 1;
	if (line[i] == '\0')
		free_parsing(all, line);
	while (ft_iswhite_space(line[i]))
		i++;
	tab[0] = check_color(all, line, i);
	while (ft_isdigit(line[i] || ft_iswhite_space(line[i])))
		i++;
	if (line[i] != ',')
		free_parsing(all, line);
	tab[1] = check_color(all, line, ++i);
	while (ft_isdigit(line[i] || ft_iswhite_space(line[i])))
		i++;
	if (line[i] != ',')
		free_parsing(all, line);
	tab[2] = check_color(all, line, ++i);
	if (*line == 'C')
		ft_color(all->ceil, tab);
	if (*line == 'F')
		ft_color(all->floor, tab);
}

void	parse_map(t_all *all, char *line)
{
	t_list	*new;

	new = ft_lstnew(ft_strdup(line));
	if (!new || !(new->content))
		free_parsing(all, line);
	ft_lstadd_back(&(all->map_ptr), new);
}

void	parse_tex(t_all *all, char *line)
{
	unsigned char	name[2];

	name[0] = line[0];
	name[1] = line[1];
	if (line[1] == '\0')
		free_parsing(all, line);
	if (name[0] == 'N' && name[1] == 'O')
		all->tex->no_texture = get_tex(all, all->tex->no_texture, line);
	if (name[0] == 'W' && name[1] == 'E')
		all->tex->we_texture = get_tex(all, all->tex->we_texture, line);
	if (name[0] == 'S' && name[1] == 'O')
		all->tex->so_texture = get_tex(all, all->tex->so_texture, line);
	if (name[0] == 'E' && name[1] == 'A')
		all->tex->ea_texture = get_tex(all, all->tex->ea_texture, line);
	else
		free_parsing(all, line);
}

void	parse_params(t_all *all, char *line)
{
	if (*line == 'F' || *line == 'C')
		parse_res(all, line);
	if (ft_is_card(*line))
		parse_tex(all, line);
}

void	parse_line(t_all *all, char *line, int ret)
{
	if (all->map_start && *line == '\0' && ret == 1)
		free_parsing(all, line);
	if (*line == '\0')
		return ;
	if (all->map_start && (!ft_isdigit(*line) && *line != 32))
		free_parsing(all, line);
	if (ft_isdigit(*line) || *line == 32)
	{
		all->map_start = 1;
		parse_map(all, line);
	}
	else
		parse_params(all, line);
}

t_all	*ft_parse(char *file)
{
	t_all	*all;

	all = ft_calloc(1, sizeof(t_all));
	check_file(all, file);
	check_allocation(all);
	read_file(all, file);
	check_parsing(all);
	return (all);
}