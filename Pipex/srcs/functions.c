/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:07:27 by Jules             #+#    #+#             */
/*   Updated: 2021/08/09 18:22:07 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int     ft_get_pos(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] && str[i] != c)
        i++;
    if (str[i] == c)
        return (i);
    return (-1);
}

char    *ft_strndup(char *str, unsigned int n)
{
    char            *dup;
    unsigned int    i;

    i = 0;
    dup = (char *)malloc(sizeof(char) * (n + 1));
    while (i < n)
    {
        dup[i] = str[i];
        i++;
    }
    dup[i] = 0;
    return (dup);
}