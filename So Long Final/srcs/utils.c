/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:32:30 by Jules             #+#    #+#             */
/*   Updated: 2021/09/21 13:25:13 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	del_list(void *list)
{
	free(list);
	list = NULL;
}

void	my_mlx_put_pxl(t_img *image, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0)
	{
		dst = image->adr + (y * image->line_length + x * (image->bits_per_pxl / 8));
		*(unsigned int *)dst = color;
	}
}

int	get_color(t_texture *text, int x, int y)
{
	char	*dst;

	dst = text->ptr + (y * text->image.line_length + x * text->image.bits_per_pxl / 8);
	return (*(unsigned int *)dst);
}

int	is_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	detect_map_line(t_all *all, char *line, t_list **error)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (!is_in_charset(line[i], "01CEP"))
		{
			add_error(all, error, "Invalid character in the map\n");
			return (0);
		}	
	}
	return (1);
}