/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:29:14 by Jules             #+#    #+#             */
/*   Updated: 2021/08/11 11:29:29 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    ft_exit(char *error_message)
{
    write(2, error_message, ft_strlen(error_message));
    write(2, "\n", 1);
    exit(0);
}
