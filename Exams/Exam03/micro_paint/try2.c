#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct	s_zone
{
	int		width;
	int		height;
	char	background;
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

void	ft_putstr(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

int	ft_fail(char *str, char **map)
{
	ft_putstr(str);
	free_map(map);
	return (1);
}

int	get_map(FILE *file, t_zone *zone)
{
	int	count;

	count = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background);
	if (count != 3)
		return (1);
	if (zone->width <= 0 || zone->width > 300 || zone->height <= 0 || zone->height > 300)
		return (1);
	return (0);
}

char	**create_map(char **map, t_zone *zone)
{
	int	i;
	int	j;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (zone->height + 1));
	if (!map)
		return (NULL);
	while (i < zone->height)
	{
		j = 0;
		map[i] = (char *)malloc(sizeof(char) * (zone->width + 1));
		if (!map)
			return (NULL);
		while (j < zone->width)
		{
			map[i][j] = zone->background;
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	print_map(char **map, t_zone *zone)
{
	int	i;

	i = 0;
	while (i < zone->height)
	{
		ft_putstr(map[i]);
		ft_putstr("\n");
		i++;
	}
}

int	is_rec(float x, float y, t_rec *rec)
{
	float	check;

	check = 1.00000000;
	if (x < rec->x || rec->x + rec->width < x || y < rec->y || rec->y + rec->height < y)
		return (0);
	if (rec->x - x < check || rec->x + rec->width - x < check || rec->y - y < check || rec->y + rec->height - y < check)
		return (2);
	return (1);
}

void	draw_zone(t_rec *rec, char **map)
{
	int	i;
	int	j;
	int	dist;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			dist = is_rec(j, i, rec);
			if ((rec->type == 'r' && dist == 2) || (rec->type == 'R' && dist))
				map[i][j] = rec->aff;
			j++;
		}
		i++;
	}
}

int	draw(FILE *file, char ***ptr)
{
	char	**map;
	int		count;
	t_rec	*rec;

	map = *ptr;
	rec = NULL;
	while ((count = fscanf(file, "%c %f %f %f %f %c\n", &rec->type, &rec->x, &rec->y, &rec->width, &rec->height, &rec->aff)) == 6)
	{
		printf("Count : %d\n", count);
		if (rec->width <= 0.00000000 || rec->height <= 0.00000000 || rec->type != 'r' || rec->type != 'R')
			return (1);
		if (rec->type == 'r' || rec->type == 'R')
		{
			draw_zone(rec, map);
			printf("Check\n");
		}
	}
	printf("Count : %d\n", count);
	if (count != 6 && count != -1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_zone	zone;
	FILE	*file;
	char	**map;

	file = NULL;
	map = NULL;
	if (ac != 2)
		return (ft_fail("Error: argument\n", map));
	file = fopen(av[1], "r");
	if (!file)
		return (ft_fail("Error: Operation file corrupted 1\n", map));
	if (get_map(file, &zone) == 1)
		return (ft_fail("Error: Operation file corrupted 2\n", map));
	if (!(map = create_map(map, &zone)))
		return (ft_fail("Error: Operation file corrupted 3\n", map));
	if (draw(file, &map))
		return (ft_fail("Error: Operation file corrupted 4\n", map));
	if (fclose(file))
		return (ft_fail("Error: Operation file corrupted 5\n", map));
	print_map(map, &zone);
	free_map(map);
}