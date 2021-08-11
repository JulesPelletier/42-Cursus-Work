/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:28:26 by Jules             #+#    #+#             */
/*   Updated: 2021/08/11 11:30:05 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    exec_cmd1(int pipefd[2], int fd_infile, char *command1, char **env)
{
    char    **args;

    close(pipefd[0]);
    args = ft_split(command1, ' ');
    if (dup2(fd_infile, STDIN) == -1)
        ft_exit("ERROR : failed to dup input with STDIN");
    if (dup2(pipefd[1], STDOUT) == -1)
        ft_exit("ERROR : failed to dup pipe with STDOUT");
    if (args[0][0] == '/')
    {
        if (execve(args[0], args, env) == -1)
            ft_exit("ERROR : invalid command");
    }
    else
        execute(args[0], args, env);
    close(fd_infile);
    close(pipefd[1]);
}

void    exec_cmd2(int pipefd[2], int fd_outfile, char *command2, char **env)
{
    char    **args;

    close(pipefd[1]);
    args = ft_split(command2, ' ');
    dup2(pipefd[0], STDIN);
	dup2(fd_outfile, STDOUT);
    if (args[0][0] == '/')
    {
        if (execve(args[0], args, env) == -1)
            ft_exit("ERROR : invalid command");
    }
    else
        execute(args[0], args, env);
    close(fd_outfile);
    close(pipefd[0]);
}