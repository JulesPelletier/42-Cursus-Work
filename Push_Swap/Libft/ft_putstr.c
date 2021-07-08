/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:52:17 by Jules             #+#    #+#             */
/*   Updated: 2021/04/27 21:53:03 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putstr(char *str)
{
    int     i;

    i = 0;
    while(str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}