#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_zone
{
	int		width;
	int		height;
	char	background;
}				t_zone;

typedef struct	s_rect
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	aff;
}				t_rect;

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

int	ft_fail(char *str, FILE *file, int err)
{
	write(1, str, ft_strlen(str));
	if (err == 1)
		fclose(file);
	return (1);
}

void	ft_free(char **map, FILE *file)
{
	int	i;

	i = 0;
	fclose(file);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**get_map(t_zone *zone, FILE *file)
{
	int		count;
	char	**map;
	int		i;
	int		j;

	count = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background);
	if (count != 3)
		return (NULL);
	if (zone->width <= 0 || zone->width > 300 || zone->height <= 0 || zone->height > 300)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (zone->height + 1));
	if (!map)
		return (NULL);
	while (i < zone->height)
	{
		map[i] = (char *)malloc(sizeof(char) * (zone->height + 1));
		j = 0;
		while (j < zone->width)
		{
			map[i][j] = zone->background;
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = "\0";
	return (map);
}

void	print_map(char **map, t_zone *zone)
{
	int	i;
	int	j;

	i = 0;
	while (i < zone->height)
	{
		j = 0;
		while (j < zone->width)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_zone	zone;
	char	**map;
	FILE	*file;

	if (ac != 2)
		return (ft_fail("Error: argument\n", NULL, 0));
	file = fopen(av[1], "r");
	if (!file)
		return (ft_fail("Error: Operation file corrupted\n", file, 0));
	if (!(map = get_map(&zone, file)))
		return (ft_fail("Error: Operation file corrupted\n", file, 1));
	print_map(map, &zone);
	ft_free(map, file);
	return (0);
}