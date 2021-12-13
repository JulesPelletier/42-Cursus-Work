/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 07:04:12 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/08 07:33:32 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_paint.h"

int		ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_exit(char *str)
{
	write(1, str, ft_strlen(str));
	return (0);
}

void	init_struct(t_all *all)
{
	all->params.background = 0;
	all->params.height = 0;
	all->params.width = 0;
	all->circle.c = 0;
	all->circle.x = 0;
	all->circle.y = 0;
	all->circle.radius = -1;
	all->map = NULL;
	all->file = NULL;
}

void	create_map(t_all *all)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (all->params.height + 1));
	while (i < all->params.height)
	{
		map[i] = (char *)malloc(sizeof(char ) * (all->params.width + 1));
		j = 0;
		while (j < all->params.width)
		{
			map[i][j] = all->params.background;
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = "\0";
	all->map = map;
}

void	show_map(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	write(1, "\n", 1);
	while (i < all->params.height)
	{
		j = 0;
		while (j < all->params.width)
		{
			write(1, &all->map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n\n", 2);

}

void	show(t_all *all)
{
	printf("Background : %c\n", all->params.background);
	printf("Height : %d\n", all->params.height);
	printf("Width : %d\n", all->params.width);
	printf("circle C : %c\n", all->circle.c);
	printf("circle X : %f\n", all->circle.x);
	printf("circle Y : %f\n", all->circle.y);
	printf("circle RADIUS : %f\n", all->circle.radius);
}

int		parsing(t_all *all)
{
	int		ret;

	ret = fscanf(all->file, "%d %d %c\n", &all->params.width, &all->params.height, &all->params.background);
	if (ret == 3)
	{
		if (all->params.width < 1 || all->params.width > 300 ||
			all->params.height < 1 || all->params.height > 300)
			return (1);
		create_map(all);
		if (!all->map)
			return (1);
	}
	return (1);
}

void	fill_map(t_all *all, int mode)
{
	int		i;
	int		j;

	i = 0;
	while (i < all->params.height)
	{
		j = 0;
		while (j < all->params.width)
		{
			if (mode == 1)
			{
				if (sqrtf(powf((float)i - all->circle.x, 2) + powf((float)j - all->circle.y, 2)) <= all->circle.radius)
					all->map[i][j] = all->circle.c;
			}
			if (mode == 2)
			{
				if (sqrtf(powf((float)i - all->circle.x, 2) + powf((float)j - all->circle.y, 2)) <= 1)
					all->map[i][j] = all->circle.c;
			}
			j++;
		}
		i++;
	}
}

int		loop(t_all *all)
{
	int		ret;

	ret = fscanf(all->file, "%c %f %f %f %c\n", &all->circle.type, &all->circle.x, &all->circle.y, &all->circle.radius, &all->circle.c);
	if (ret != 5)
		return (0);
	if (all->circle.type == 'C')
		fill_map(all, 1);
	if (all->circle.type == 'c')
		fill_map(all, 2);
	return (1);
}

int		main(int ac, char **av)
{
	t_all	all;
	int		i;
	
	init_struct(&all);
	if (ac == 1)
		return (ft_exit("Error : argument\n"));
	i = 1;
	while (i < ac)
	{
		if ((all.file = fopen(av[i], "r")) == NULL)
			ft_exit("Failed to open file\n");
		else
		{
			parsing(&all);
			//show(&all);
			create_map(&all);
			show_map(&all);
			while (loop(&all))
				;
			show_map(&all);
		}
		i++;
	}
	free(all.map);
	return (0);
}