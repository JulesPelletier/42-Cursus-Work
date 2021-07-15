/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_keypress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:28:12 by Jules             #+#    #+#             */
/*   Updated: 2021/07/09 15:27:23 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_keys_keypress_various(int key, t_st *st)
{
	if (key == 112)
		st->keys.plus = 1;
	if (key == 109)
		st->keys.minus = 1;
	if (key == 65307)
		st->keys.esc = 1;
}

void	ft_keys_keypress_directions(int key, t_st *st)
{
	if (key == 119)
		st->keys.w = 1;
	if (key == 97)
		st->keys.a = 1;
	if (key == 115)
		st->keys.s = 1;
	if (key == 100)
		st->keys.d = 1;
	if (key == 65362)
		st->keys.up = 1;
	if (key == 65364)
		st->keys.down = 1;
	if (key == 65361)
		st->keys.left = 1;
	if (key == 65363)
		st->keys.right = 1;
}

int		ft_keys_keypress(int key, t_st *st)
{
	ft_keys_keypress_directions(key, st);
	ft_keys_keypress_various(key, st);
	return (0);
}
