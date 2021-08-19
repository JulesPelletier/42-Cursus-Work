/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:28:54 by Jules             #+#    #+#             */
/*   Updated: 2021/08/19 16:04:03 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int check_extension(char *str)
{
    int     i;
    char    *extension;

    i = 0;
    extension = NULL;
    if (!str)
        return (-1);
    while (str[i] != '.')
        i++;
    extension = (char *)&str[i + 1];
    if (ft_strncmp(extension, "ber", ft_strlen(extension)) != 0)
    {
        errors_part1(3);
        return (-1);
    }
    return (1);
}