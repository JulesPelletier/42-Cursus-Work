/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:12:00 by Jules             #+#    #+#             */
/*   Updated: 2021/08/11 11:12:12 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int ac, char **av, char **env)
{
    if (ac == 5)
        ft_pipex(ac, av, env);
    else
        ft_exit("ERROR : use ./pipex [file1][command1][command2][file2]");
    return (0);
}