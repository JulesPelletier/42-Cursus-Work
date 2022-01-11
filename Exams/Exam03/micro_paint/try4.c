#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

typedef struct	s_zone
{
	int		width;
	int		height;
	char	background
}				t_zone;

typedef struct s_rec
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	aff;
}				t_rec;

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

int	ft_putstr(char *str, int err)
{
	write(1, str, ft_strlen(str));
	return (err);
}

char	*get_map(FILE *file, t_zone *zone)
{
	int		count;
	char	*map;
	int		i;

	count = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background);
	if (count != 3)
		return (NULL);
	if (zone->width <= 0 || zone->width > 300 || zone->height <= 0 || zone->height > 300)
		return (NULL);
	map = (char *)malloc(sizeof(char) * (zone->width * zone->height));
	if (!map)
		return (NULL);
	i = 0;
	while (i < (zone->width * zone->height))
	{
		map[i] = zone->background;
		i++;
	}
	return (map);
}

int	cal_dist(float x, float y, t_rec *rec)
{
	float	check;

	check = 1.00000000;
	if ((x < rec->x || rec->x + rec->width < x) || (y < rec->y || rec->y + rec->height < y))
		return (0);
	if (x - rec->x < check || rec->x + rec->width - x < check || y - rec->y < check || rec->y + rec->height - y < check)
		return (2);
	return (1);
}

void	print_map(char *map, t_zone *zone)
{
	int	i;

	i = 0;
	while (i < zone->height)
	{
		write(1, map + (i * zone->width), zone->width);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_zone	zone;
	FILE	*file;
	char	*map;

	if (ac != 2)
		return (ft_putstr("Error: argument\n", 1));
	if (!(file = fopen(av[1], "r")))
		return (ft_putstr("Error: Operation file corrupted\n", 1));
	if (!(map = get_map(file, &zone)))
	{
		fclose(file);
		return (ft_putstr("Error: Operation file corrupted\n", 1));
	}
	print_map(map, &zone)
	return (0);
}