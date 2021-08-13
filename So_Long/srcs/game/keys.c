/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:45:32 by Jules             #+#    #+#             */
/*   Updated: 2021/08/12 17:34:29 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

void    ft_keypress(t_all *all, int key)
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

void    ft_keyrelease(t_all *all, int key)
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

int keypress(t_all *all, int key)
{
    printf("Key Pressed : %d\n", key);
    ft_keypress(all, key);
    return (1);
}

int keyrelease(t_all *all, int key)
{
    printf("Key Released : %d\n", key);
    ft_keyrelease(all, key);
    return (1);
}

int ft_keys(t_all *all)
{
    if (all->keys.key_w == 1)
        show_keys(all);
    if (all->keys.key_a == 1)
        show_keys(all);
    if (all->keys.key_s == 1)
        show_keys(all);
    if (all->keys.key_d == 1)
        show_keys(all);
    if (all->keys.key_esc == 1)
        show_keys(all);
    return (0);
}