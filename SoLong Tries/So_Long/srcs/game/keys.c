/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:45:32 by Jules             #+#    #+#             */
/*   Updated: 2021/08/19 17:48:52 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void    ft_keypress(int key, t_all *all)
{
    if (key == 13)
        all->keys.key_w = 1;
    if (key == 0)
        all->keys.key_a = 1;
    if (key == 1)
        all->keys.key_s = 1;
    if (key == 2)
        all->keys.key_d = 1;
    if (key == 53)
        all->keys.key_esc = 1;
}

void    ft_keyrelease(int key, t_all *all)
{
	if (key == 13)
        all->keys.key_w = 0;
    if (key == 0)
        all->keys.key_a = 0;
    if (key == 1)
        all->keys.key_s = 0;
    if (key == 2)
        all->keys.key_d = 0;
    if (key == 53)
        all->keys.key_esc = 0;
}

int keypress(int key, t_all *all)
{
    ft_keypress(key, all);
    ft_keys(all);
    return (1);
}

int keyrelease(int key, t_all *all)
{
    ft_keyrelease(key, all);
    return (1);
}

void    ft_keys(t_all *all)
{
    if (all->keys.key_w == 1)
        move_up(all);
    if (all->keys.key_a == 1)
        move_left(all);
    if (all->keys.key_s == 1)
        move_down(all);
    if (all->keys.key_d == 1)
        move_right(all);
    if (all->keys.key_esc == 1)
        escape(all);
}