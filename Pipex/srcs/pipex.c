/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 09:54:40 by Jules             #+#    #+#             */
/*   Updated: 2021/08/09 11:58:21 by Jules            ###   ########.fr       */
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
            return (0);
        }
        return (open(filename, O_RDONLY));
    }
    else
        return (open(filename, O_CREAT | O_WRONLY | O_TRUNC,
            S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
}

void    execute_command(char *command, char **env)
{
    char    **arg;
    char    *path;

    arg = env;
    path = command;

}

void    redirect(char *command, char **env, int fd_in)
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

int main(int ac, char **av)
{
    t_pipex pipex;
    
    if (ac == 5)
    {
        pipex.infile = av[1];
        pipex.fd_in = ft_open(pipex.infile, 1);
        pipex.outfile = av[ac - 1];
        printf("Infile : %s\n", pipex.infile);
        pipex.fd_out = ft_open(pipex.outfile, 2);
        printf("Outfile : %s\n", pipex.outfile);
        dup2(pipex.fd_in, STDIN);
        printf("Fd IN : %d\n", pipex.fd_in);
        printf("Fd OUT : %d\n", pipex.fd_out);
        //dup2(pipex.fd_out, STDOUT);
        printf("Fd OUT : %d\n", pipex.fd_out);
        pipex.command1 = av[2];
        pipex.command2 = av[3];
        printf("Command 1 : %s\n", pipex.command1);
        printf("Command 2 : %s\n", pipex.command2);
    }
    /*
    else
    {
        printf("%s\n", strerror(1));
        printf("%s\n", strerror(2));
        printf("%s\n", strerror(3));
        printf("%s\n", strerror(4));
    }
    */
}