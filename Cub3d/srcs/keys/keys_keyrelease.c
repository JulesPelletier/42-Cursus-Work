/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_keyrelease.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:29:03 by Jules             #+#    #+#             */
/*   Updated: 2021/07/16 13:30:20 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_keys_keyrelease_various(int key, t_st *st)
{
	if (key == 24)
	{
		st->keys.plus = 0;
		st->keys.keepplus = 0;
	}
	if (key == 27)
	{
		st->keys.minus = 0;
		st->keys.keepminus = 0;
	}
	if (key == 53)
		st->keys.esc = 0;
}

void	ft_keys_keyrelease_directions(int key, t_st *st)
{
	if (key == 13)
		st->keys.w = 0;
	if (key == 0)
		st->keys.a = 0;
	if (key == 1)
		st->keys.s = 0;
	if (key == 2)
		st->keys.d = 0;
	if (key == 126)
		st->keys.up = 0;
	if (key == 125)
		st->keys.down = 0;
	if (key == 123)
		st->keys.left = 0;
	if (key == 124)
		st->keys.right = 0;
}

int	ft_keys_keyrelease(int key, t_st *st)
{
	ft_keys_keyrelease_directions(key, st);
	ft_keys_keyrelease_various(key, st);
	return (0);
}
