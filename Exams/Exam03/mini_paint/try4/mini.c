/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:01:14 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/10 18:39:25 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct	s_zone
{
	int		width;
	int		height;
	char	background;
}				t_zone;

typedef struct	s_list
{
	char	type;
	float	x;
	float	y;
	float	radius;
	char	color;
}				t_list;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	fail(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int	free_all(FILE *file, char *str)
{
	fclose(file);
	if (str)
		free(str);
	return (1);
}

char	*get_zone(FILE *file, t_zone *zone)
{
	int		i;
	char	*array;

	if ((i = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background)) != 3)
		return (NULL);
	if (zone->width <= 0 || zone->width > 300 || zone->height <= 0 || zone->height > 300)
		return (NULL);
	if (!(array = (char *)malloc(sizeof(char) * (zone->width * zone->height))))
        return (NULL);
	i = 0;
	while (i < (zone->width * zone->height))
	{
		array[i] = zone->background;
		i++;
	}
	return (array);
}

int	is_rad(float x, float y, t_list *cercle)
{
	float	dist;
	float	check;

	check = 1.00000000;
	dist = sqrtf(((x - cercle->x) * (x - cercle->x)) + ((y - cercle->y) * (y - cercle->y)));
	if (dist <= cercle->radius)
	{
		if ((cercle->radius - dist) < check)
			return (2);
		return (1);
	}
	return (0);
}

void	get_draw(t_list *cercle, t_zone *zone, char *draw)
{
	int	x;
	int	y;
	int	rad;

	y = 0;
	while (y < zone->height)
	{
		x = 0;
		while (x < zone->width)
		{
			rad = is_rad((float)x, (float)y, cercle);
			if ((rad == 2 && cercle->type == 'c') || (rad && cercle->type == 'C'))
				draw[(y * zone->width) + x] = cercle->color;
			x++;
		}
		y++;
	}
}

int	drawing(FILE *file, t_zone *zone, char *draw)
{
	t_list	cercle;
	int		count;

	while ((count = fscanf(file, "%c %f %f %f %c\n", &cercle.type, &cercle.x, &cercle.y, &cercle.radius, &cercle.color)) == 5)
	{
		printf("Count : %d\n", count);
		if (cercle.radius <= 0.0000000 && (cercle.type != 'c' || cercle.type != 'C'))
			return (0);
		get_draw(&cercle, zone, draw);
	}
	printf("Count : %d\n", count);
	if (count != -1)
		return (0);
	return (1);
}

void	print_draw(char *draw, t_zone *zone)
{
	int	i;

	i = 0;
	while (i < zone->height)
	{
		write(1, draw + (i * zone->width), zone->width);
		write(1, "\n", 1);
		i++;
	}
}

int main(int ac, char **av)
{
    t_zone zone;
    char *draw;
    FILE *file;

    if (ac != 2)
        return (fail("Error: argument\n"));
    if (!(file = fopen(av[1], "r")))
        return (fail("Error: Operation file corrupted\n"));
    if (!(draw = get_zone(file, &zone)))
        return (free_all(file, NULL) && fail("Error: Operation file corrupted\n"));
    if (!(drawing(file, &zone, draw)))
        return (free_all(file, draw) && fail("Error: Operation file corrupted\n"));
    print_draw(draw, &zone);
    free_all(file, draw);
    return (0);
}