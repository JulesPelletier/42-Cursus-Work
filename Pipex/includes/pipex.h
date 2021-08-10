/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 09:46:47 by Jules             #+#    #+#             */
/*   Updated: 2021/08/09 18:18:22 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../Libft/libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct  s_pipex
{
    int     fd_in;
    int     fd_out;
    char    *infile;
    char    *outfile;
    char    *path;
    char    *command1;
    char    *command2;
}               t_pipex;

int     ft_get_pos(char *str, char c);
char    *ft_strndup(char *str, unsigned int n);

int     ft_open(char *filename, int n);

#endif 