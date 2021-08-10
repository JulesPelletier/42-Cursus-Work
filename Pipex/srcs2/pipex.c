/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:42:57 by julpelle          #+#    #+#             */
/*   Updated: 2021/08/10 12:35:45 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int ft_open(char *filename, int n)
{
    if (n == 1)
    {
        if (access(filename, F_OK))
        {
            write(STDERR, "No such file\n", 14);
            return (STDIN);
        }
        return (open(filename, O_RDONLY));
    }
    else
        return (open(filename, O_CREAT | O_WRONLY | O_TRUNC,
            S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
}

void    exec_cmd1(int ac, char **av, char **env, int *fd)
{
    int     infile;
    char    *command1

    clsoe(fd[0]);
    dup2(fd[1], STDOUT);
    close(fd[1]);
    infile = ft_open(av[1], 0);
    if (infile == -1)
        exit(0);
    dup2(infile, STDIN);
    command1 = ft_split(av[2], ' ');

}

void    exec_cmd2(int *fd, int f2)
{
    dup2(f2, STDIN);
    dup2(fd[0], STDOUT);
}


void    pipex(int f1, int f2)
{
    int     *fd[2];
    int     status;
    t_pid   child1;
    t_pid   child2;

    status = 0;
    pipe(fd);
    child1 = fork();
    if (child1 < 0)
        return (perror("Fork : "));
    if (child1 == 0)
        exec_cmd1(child1, command1);
    child2 = fork();
    if (child2 < 0)
        return (perror("Fork : "));
    if (child2 == 0)
        exec_cmd2(child2, command2);
    close(fd[0]);
    close(fd[1]);
    waitpid(-1, &status, 0);
}