/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:42:57 by julpelle          #+#    #+#             */
/*   Updated: 2021/08/10 16:59:03 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    ft_exit(char *error_message)
{
    write(2, error_message, ft_strlen(error_message));
    write(2, "\n", 1);
    exit(0);
}

void    ft_path(char *command, char **args, char **paths, char **env)
{
    int     i;
    char    *tmp;
    char    *path;

    int j=0;
    ft_putstr("Affichage ARGS");
    while (args[j])
    {
        ft_putstr(args[j]);
        j++;
    }
    ft_putstr("\n");

    i = 0;
    while (paths[i])
    {
        tmp = ft_strjoin(paths[i], "/");
        path = ft_strjoin(tmp, command);
        ft_putstr("CHECK before execve\n\n");
        ft_putstr(tmp);
        ft_putstr("\n");
        ft_putstr(path);
        ft_putstr("\n");
        execve(path, args, env);
        ft_putstr("END execve");
        free(path);
        free(tmp);
        i++;
    }
    ft_exit("ERROR path");
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
            /*
            int j=0;
            while (paths[j])
            {
                ft_putstr(paths[j]);
                ft_putstr("\n");
                j++;
            }
            */
            break;
        }
        i++;
    }
    ft_path(command, args, paths, env);
}

void    exec_cmd1(int pipefd[2], int fd_infile, char *command1, char **env)
{
    char    **args;

    close(pipefd[0]);
    args = ft_split(command1, ' ');
    if (dup2(fd_infile, 0) == -1)
        ft_exit("ERROR : failed to dup input with STDIN");
    if (dup2(pipefd[1], 1) == -1)
        ft_exit("ERROR : failed to dup outfile with STDOUT");
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
    dup2(pipefd[0], 0);
	dup2(fd_outfile, 1);
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

void    ft_pipex(int ac, char **av, char **env)
{
    int     fd_infile;
    int     fd_outfile;
    int     pipefd[2];
    pid_t   pid;

    fd_infile = open(av[1], O_RDONLY);
    if (fd_infile == -1)
        ft_exit("ERROR : Failed to open input file");
    fd_outfile = open(av[ac - 1], O_RDWR);
    if (fd_outfile == -1)
        ft_exit("ERROR : Failed to open output file");
    pid = fork();
    if (pid < 0)
        ft_exit("ERROR : Failed to fork");
    if (pid == 0)
    {
        ft_putstr("CHECK COMMAND 2\n");
        exec_cmd2(pipefd, fd_outfile, av[3], env);
    }
    else
    {
        ft_putstr("CHECK COMMAND 1\n");
        exec_cmd1(pipefd, fd_infile, av[2], env);
    }
}

int main(int ac, char **av, char **env)
{
    if (ac == 5)
        ft_pipex(ac, av, env);
    else
        ft_exit("ERROR : use ./pipex [file1][command1][command2][file2]");
    return (0);
}