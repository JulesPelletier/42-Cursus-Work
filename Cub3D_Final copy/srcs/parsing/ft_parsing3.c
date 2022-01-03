/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:32:01 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/02 22:29:53 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_map(t_info *info)
{
	int		line;
	int		pos_index;
	t_list	*ptr;

	line = -1;
	pos_index = -1;
	if (ft_lstsize(info->map_ptr) < 3)
		parsing_error(NULL, info, "map too small\n");
	ptr = info->map_ptr;
	while (ptr)
	{
		if (pos_index == -1)
			++line;
		if (!ft_is_good_mapchar((char *)ptr->content))
			parsing_error(NULL, info, "character invalid in map description\n");
		pos_index = find_pos((char *)ptr->content, info, pos_index);
		ptr = ptr->next;
	}
	if (pos_index == -1)
		parsing_error(NULL, info, "there must be a player in the map\n");
	ff_check(info, pos_index, line);
}

t_texture	*handle_text(t_info *info, t_texture *text, char *line)
{
	if (text)
		free_texture(info->mlx_ptr, text);
	return (get_texture(line, info));
}

void	parsing_text(char *line, t_info *info)
{
	unsigned char	begin[2];

	begin[0] = line[0];
	begin[1] = line[1];
	if (line[1] == '\0')
		parsing_error(line, info, "texture line invalid\n");
	if (begin[0] == 'N' && begin[1] == 'O')
		info->no_texture = handle_text(info, info->no_texture, line);
	else if (begin[0] == 'W' && begin[1] == 'E')
		info->we_texture = handle_text(info, info->we_texture, line);
	else if (begin[0] == 'E' && begin[1] == 'A')
		info->ea_texture = handle_text(info, info->ea_texture, line);
	else if (begin[0] == 'S' && begin[1] == 'O')
		info->so_texture = handle_text(info, info->so_texture, line);
	else
		parsing_error(line, info, "unknown type identifier\n");
}

void	set_color(unsigned char color[4], unsigned char r, unsigned char g,
unsigned char b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
	color[3] = 0;
}

void	parsing_color(char *line, t_info *info)
{
	int				i;
	unsigned char	color[3];

	i = 1;
	if (line[i] == '\0')
		parsing_error(line, info, "color line invalid\n");
	while (ft_iswhitespace(line[i]))
		i++;
	color[0] = get_color(line, info, i);
	while (ft_isdigit(line[i]) || ft_iswhitespace(line[i]))
		i++;
	if (line[i] != ',')
		parsing_error(line, info, "color line incomplete\n");
	color[1] = get_color(line, info, ++i);
	while (ft_isdigit(line[i]) || ft_iswhitespace(line[i]))
		i++;
	if (line[i] != ',')
		parsing_error(line, info, "color line incomplete\n");
	color[2] = get_color(line, info, ++i);
	if (*line == 'C')
		set_color(info->ceil, color[0], color[1], color[2]);
	if (*line == 'F')
		set_color(info->floor, color[0], color[1], color[2]);
}
