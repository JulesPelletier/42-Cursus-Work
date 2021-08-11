/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 09:46:47 by Jules             #+#    #+#             */
/*   Updated: 2021/08/11 11:33:15 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../Libft/libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

void    ft_exit(char *error_message);
void    exec_cmd1(int pipefd[2], int fd_infile, char *command1, char **env);
void    exec_cmd2(int pipefd[2], int fd_outfile, char *command2, char **env);
void    ft_path(char *command, char **args, char **paths, char **env);
void    execute(char *command, char **args, char **env);
void    ft_pipex(int ac, char **av, char **env);

#endif 