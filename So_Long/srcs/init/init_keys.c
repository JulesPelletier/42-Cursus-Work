/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:47:25 by Jules             #+#    #+#             */
/*   Updated: 2021/08/12 13:48:15 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/solong.h"

void    init_keys(t_all *all)
{
    all->keys.key_w = 0;
    all->keys.key_a = 0;
    all->keys.key_s = 0;
    all->keys.key_d = 0;
    all->keys.key_esc = 0;
}