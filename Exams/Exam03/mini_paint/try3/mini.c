/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:32:02 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/13 15:59:28 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_paint.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_exit(char *str)
{
	ft_putstr(str);
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
	all->circle.c = 0;
	all->circle.x = 0;
	all->circle.y = 0;
	all->circle.radius = -1;
	all->map = NULL;
	all->file = NULL;
}

FILE	*open_file(char *str)
{
	FILE	*file;

	file = fopen(str, "r");
	if (file == NULL)
	{
		ft_putstr("Failed to open file\n");
		return (NULL);
	}
	return (file);
}

int	parse(t_all *all)
{
	int	i;
	
	if ((i = fscanf(all->file, "%d %d %c \n", &all->params.width, &all->params.height, &all->params.background)) != 3)
		return (-1);
	return (1);
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

void	show_map(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->params.height)
	{
		j = 0;
		while (j < all->params.width)
		{
			ft_putchar(all->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n\n");
}

void	create_map(t_all *all)
{
	char	**buffer;
	int		i;
	int		j;

	buffer = (char **)malloc(sizeof(char *) * (all->params.height + 1));
	i = 0;
	while (i < all->params.height)
	{
		buffer[i] = (char *)malloc(sizeof(char) * (all->params.width + 1));
		j = 0;
		while (j < all->params.width)
		{
			buffer[i][j] = all->params.background;
			j++;
		}
		buffer[i][j] = '\0';
		i++;
	}
	buffer[i] = "\0";
	all->map = buffer;
}

int	algo(t_all *all)
{
	int	count;
	int i;
	int	j;

	if ((count = fscanf(all->file, "%c %f %f %f %c \n", &all->circle.type, &all->circle.x, &all->circle.y, &all->circle.radius, &all->circle.c)) != 5)
		return (-1);
	i = 0;
	printf("Params Algo : \n\tType : %c\n\tX : %f\n\tY : %f\n\tRadius : %f\n\tChar : %c\n", all->circle.type, all->circle.x, all->circle.y, all->circle.radius, all->circle.c);
	while (i < all->params.height)
	{
		j = 0;
		while (j < all->params.width)
		{
			if (all->circle.type == 'C')
			{
				//printf("Check C !\n");
				//printf("Test : %f | %f | %f\n", powf((float)i - all->params.height, 2), powf((float)j - \
				//	all->params.width, 2), sqrtf(powf((float)i - all->circle.x, 2) + powf((float)j - all->circle.y, 2)));
				if (sqrtf(powf((float)i - all->circle.x, 2) + powf((float)j - all->circle.y, 2)) <= all->circle.radius)
					all->map[i][j] = all->circle.c;
			}
			if (all->circle.type == 'c')
			{
				//printf("Check c !\n");
				//printf("Test : %f | %f | %f\n", powf((float)i - all->params.height, 2), powf((float)j - \
				//	all->params.width, 2), sqrtf(powf((float)i - all->circle.x, 2) + powf((float)j - all->circle.y, 2)));
				if (sqrtf(powf((float)i - all->circle.x, 2) + powf((float)j - all->circle.y, 2)) == all->circle.radius)
					all->map[i][j] = all->circle.c;
			}
			j++;
		}
		i++;
	}
	show_map(all);
	return (1);
}

int	main(int ac, char **av)
{
	t_all	all;
	int		i;

	init_struct(&all);
	if (ac == 1)
		return (ft_exit("Error : argument\n"));
	i = 1;
	while (i < ac)
	{
		all.file = open_file(av[i]);
		if (parse(&all) == -1)
			ft_putstr("Error : parsing failed\n");
		create_map(&all);
		while (algo(&all) != -1)
			;
		i++;
	}
}
