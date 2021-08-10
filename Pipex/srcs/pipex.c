/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 09:54:40 by Jules             #+#    #+#             */
/*   Updated: 2021/08/10 11:38:47 by julpelle         ###   ########.fr       */
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

char    *ft_get_path(char *command1, char **env)
{
    char    *path;
    char    *dir;
    char    *tmp;
    int     i;

    i = 0;
    while (env[i] && ft_strncmp(env[i], "PATH=", 5))
        i++;
    if (!env[i])
        return (command1);
    path = env[i] + 5;
    while (path && ft_get_pos(path, ':') > -1)
    {
        dir = ft_strndup(path, ft_get_pos(path, ':'));
        tmp = ft_strjoin(dir, command1);
        free(dir);
        if (access(tmp, F_OK) == 0)
            return (tmp);
        free(tmp);
        path += ft_get_pos(path, ':') + 1;
    }
    return (command1);
}

void    execute_command(char *command, char **env)
{
    char    **arg;
    char    *path;
    int     i;

    i = 0;
    (void)path;
    (void)env;
    arg = ft_split(command, ' ');
    if (ft_get_pos(arg[0], '/') > -1)
        path = arg[0];
    else
        path = ft_get_path(arg[0], env);
    execve(path, arg, env);
    if (access(command, F_OK) == 0)
        write(STDERR, "The command was not found\n", 27);
    exit(127);
}

void    f_pipex(char *command, char **env, int fd_in)
{
    pid_t   pid;
    int     pipefd[2];

    pipe(pipefd);
    if (pipe(pipefd) == -1)
    {
        perror("pipe : ");
        exit(1);
    }
    pid = fork();
    if (pid)
    {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN);
        waitpid(pid, NULL, 0);
    }
    else
    {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT);
        if (fd_in == 0)
            exit(1);
        else
            execute_command(command, env);
    }
}

void    test_aff(t_pipex pipex)
{
        printf("Infile : %s\n", pipex.infile);
        printf("Outfile : %s\n", pipex.outfile);
        printf("Fd IN : %d\n", pipex.fd_in);
        printf("Fd OUT : %d\n", pipex.fd_out);
        printf("Command 1 : %s\n", pipex.command1);
        printf("Command 2 : %s\n", pipex.command2);
}

int main(int ac, char **av, char **env)
{
    t_pipex pipex;
    
    if (ac == 5)
    {
        pipex.infile = av[1];
        pipex.fd_in = ft_open(pipex.infile, STDIN);
        pipex.outfile = av[ac - 1];
        pipex.fd_out = ft_open(pipex.outfile, STDOUT);
        dup2(pipex.fd_in, STDIN);
        dup2(pipex.fd_out, STDOUT);
        pipex.command1 = av[2];
        pipex.command2 = av[3];
        test_aff(pipex);
        f_pipex(pipex.command1, env, pipex.fd_in);
        execute_command(pipex.command2, env);
    }
    else
    {
        write(STDERR, "Number of arguments incorrect\n", 31);
        write(STDERR, "([file1][command1][command2][file2])\n", 38);
    }
    return (0);
}