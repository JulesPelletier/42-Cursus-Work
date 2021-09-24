/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:58:31 by Jules             #+#    #+#             */
/*   Updated: 2021/09/21 13:25:49 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	main(int ac, char **av)
{
	t_all	all;
	t_list	*map;
	t_list	*error;

	map = NULL;
	error = NULL;
	init_all(&all);
	if (!check_arguments(&all, ac, av[1], &error))
	{
		init_game(&all, av[1], &map, &error);
		if (!error)
			create_map(&all, map, &error);
		if (!error)
		{
			ft_lstclear(&map, &del_list);
			load_map(&all);
		}
	}
	if (error)
		show_errors(error);
}