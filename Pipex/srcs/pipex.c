/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:42:57 by julpelle          #+#    #+#             */
/*   Updated: 2021/08/28 13:05:08 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    ft_path(char *command, char **args, char **paths, char **env)
{
    int     i;
    char    *tmp;
    char    *path;

    i = 0;
    while (paths[i])
    {
        tmp = ft_strjoin(paths[i], "/");
        path = ft_strjoin(tmp, command);
        execve(path, args, env);
        free(path);
        free(tmp);
        i++;
    }
    ft_putstr_fd("ERROR : ", STDOUT);
    ft_putstr_fd(command, STDOUT);
    ft_putstr_fd(" doesn't exist\n", STDOUT);
}

void    execute(char *command, char **args, char **env)
{
    int     i;
    char    **paths;
    
    i = 0;
    paths = NULL;
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH", 4) == 0)
        {
            env[i] = env[i] + 5;
            paths = ft_split(env[i], ':');
            break;
        }
        i++;
    }
    ft_path(command, args, paths, env);
}

void    ft_pipex(int ac, char **av, char **env)
{
    int     fd_infile;
    int     fd_outfile;
    int     pipefd[2];
    pid_t   pid1;
    pid_t   pid2;

    fd_infile = open(av[1], O_RDONLY);
    fd_outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd_infile == -1)
    {
        if (fd_outfile == -1)
            ft_exit("ERROR : Failed to open input file");
    }
    if (pipe(pipefd) == -1)
        ft_exit("Failed to create the pipe process");
    pid1 = fork();
    if (pid1 < 0)
        ft_exit("ERROR : Failed to fork");
    if (pid1 == 0)
        exec_cmd1(pipefd, fd_infile, av[2], env);
    pid2 = fork();
    if (pid2 < 0)
        ft_exit("ERROR : Failed to fork");
    if (pid2 == 0)
        exec_cmd2(pipefd, fd_outfile, av[3], env);
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}