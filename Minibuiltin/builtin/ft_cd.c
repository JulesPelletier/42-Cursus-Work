#include "../lib_jules.h"

void	ft_swap_env_pwd(char *arg)
{
	ft_del_variable("OLDPWD");
	ft_add_env(ft_strjoin("OLDPWD=", getenv("PWD")));
	ft_del_variable("PWD");
	ft_add_env(ft_strjoin("PWD=", arg));
}

void    ft_cd_noargs(void)
{
    char    *arg;

    arg = getenv("HOME");
    printf("ARG : %s\n", arg);
    if (!arg)
        ft_putstr_fd("cd : HOME doesn't exist\n", 1);
    else if (chdir(arg) != 0)
        ft_putstr_fd("cd : no such file or directory\n", 1);
    else
    {
        ft_swap_env_pwd(arg);
        ft_pwd("pwd");
    }
}

void    ft_cd_minus(char **args)
{
    char    *path;
    printf("ARG : %s\n", *args);
    if (!ft_strncmp(*args, "-", 2))
    {
        path = getenv("OLDPWD");
        if (!path)
            ft_putstr_fd("cd : OLDPWD is not set\n", 1);
        if (chdir(path) != 0)
            ft_putstr_fd("cd : no such file or directory\n", 1);
        else
        {
            ft_swap_env_pwd(path);
            ft_pwd("pwd");
        }
    }
    else
        ft_putstr_fd("Invalid option\n", 1);
}

void    ft_cd_other(char **args)
{
    char    *path;

    if (chdir(*args) != 0)
        ft_putstr_fd("cd : error\n", 1);
    else
    {
        path = getcwd(NULL, 0);
        ft_swap_env_pwd(path);
        ft_pwd("pwd");
    }
}

void    ft_cd_arg(char **args)
{
    if (*args[0] == '-')
        ft_cd_minus(args);
    else
    {
        if (*args[0] == '/')
        {
            if (chdir(*args) != 0)
                ft_putstr_fd("cd : error\n", 1);
            else
            {
                ft_swap_env_pwd(*args);
                ft_pwd("pwd");
            }
        }
        else
            ft_cd_other(args);
    }
}

void    ft_cd(char *command, char **args, char **envp)
{
    (void)envp;
    (void)command;
    printf("IN CD Function\n");
    if (!(*args))
        ft_cd_noargs();
    else
        ft_cd_arg(args);
}