#include "lib_jules.h"

int main(int ac, char **av, char **envp)
{
    int i;
    char    *command;
    char    **args;

    i = 0;
    (void)ac;
    command = ft_strdup(av[1]);
    args = &av[2];
    args[ac] = "\0";
    ft_init_env(envp);
    menu(command, args, envp);
    return (0);
}