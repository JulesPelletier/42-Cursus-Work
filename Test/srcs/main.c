/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:38:34 by Jules             #+#    #+#             */
/*   Updated: 2021/09/16 01:54:52 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	main(int argc, char **argv)
{
	t_all	all;

	init_all(&all);
	if (argc != 2)
		error(&all, 2);
	if (!check_file(argv[1]))
		error(&all, 2);
	all.args.fd = open(argv[1], O_DIRECTORY);
	if (all.args.fd != -1)
		error(&all, 2);
	all.args.fd = open(argv[1], O_RDONLY);
	if (all.args.fd == -1)
		error(&all, 2);
	map_parsing(&(all.args), &all);
	start_pos(&all);
	printf("Size x : %d\n", all.map.size_x);
	printf("Size y : %d\n", all.map.size_y);
	all.collectibles = 1;
	all.exit = 1;
	game_loop(&all);
	clear_images(&all);
	return (0);
}
