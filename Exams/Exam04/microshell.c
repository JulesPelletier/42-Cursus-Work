/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:10:09 by julpelle          #+#    #+#             */
/*   Updated: 2022/06/01 19:37:00 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define TYPE_PIPE 3
# define TYPE_BREAK 4
# define TYPE_END 5

typedef struct	s_all
{
	char **av;
	int	size;
	int	type;
	int fd[2];
	struct s_all *next;
	struct s_all *prev;
}				t_all;

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int 	size;
	char	*res;
	int		i;
	
	if (!str)
		return (NULL);
	size = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	ft_lst_addback(t_all **ptr, t_all *new)
{
	t_all *tmp;

	if (!(*ptr))
		*ptr = new;
	else
	{
		tmp = *ptr;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

int		size_arg(char **av)
{
	int i;

	i = 0;
	while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
		i++;
	return (i);
}

int	check_end(char *str)
{
	if (!str)
		return (TYPE_END);
	if (strcmp(str, "|") == 0)
		return (TYPE_PIPE);
	if (strcmp(str, ";") == 0)
		return (TYPE_BREAK);
	return (0);
}


void exit_fatal(void)
{
	write(STDERR, "error: fatal\n", ft_strlen("error: fatal\n"));
	exit(EXIT_FAILURE);
}

void exit_execve(char *str)
{
	write(STDERR, "error: cannot execute ", ft_strlen("error: cannot execute "));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	exit(EXIT_FAILURE);
}

int exit_cd_1()
{
	write(STDERR, "error: cd: bad arguments\n", ft_strlen("error: cd: bad arguments\n"));
	return (EXIT_FAILURE);
}

int exit_cd_2(char *str)
{
	write(STDERR, "error: cd: cannot change directory to ", ft_strlen("error: cd: cannot change directory to "));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	return (EXIT_FAILURE);
}

int	parser_av(t_all **ptr, char **av)
{
	int		size;
	t_all	*new;
	int		i;
	
	size = size_arg(av);
	new = (t_all *)malloc(sizeof(t_all));
	if (!new)
		exit_fatal();
	new->av = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new->av)
		exit_fatal();
	new->size = size;
	new->next = NULL;
	new->prev = NULL;
	i = 0;
	while (i < size)
	{
		new->av[i] = ft_strdup(av[i]);
		i++;
	}
	new->av[i] = NULL;
	new->type = check_end(av[new->size]);
	ft_lst_addback(ptr, new);
	return (new->size);
}

void	exec_cmd(t_all *tmp, char **env)
{
	pid_t	pid;
	int		status;
	int		pipe_open;

	pipe_open = 0;
	if (tmp->type == TYPE_PIPE || (tmp->prev && tmp->prev->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(tmp->fd))
			exit_fatal();
	}
	pid = fork();
	if (pid < 0)
		exit_fatal();
	else if (pid == 0)
	{
		if (tmp->type == TYPE_PIPE && dup2(tmp->fd[STDOUT], STDOUT) < 0)
			exit_fatal();
		if (tmp->prev && tmp->prev->type == TYPE_PIPE && dup2(tmp->fd[STDIN], STDIN) < 0)
			exit_fatal();
		if (execve(tmp->av[0], tmp->av, env) < 0)
			exit_execve(tmp->av[0]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(tmp->fd[STDOUT]);
			if (!tmp->next || tmp->type == TYPE_BREAK)
				close(tmp->fd[STDIN]);
		}
		if (tmp->prev && tmp->prev->type == TYPE_PIPE)
			close(tmp->fd[STDIN]);
	}
}

void	exec_cd(t_all *ptr, char **env)
{
	t_all *tmp;

	tmp = ptr;
	while (tmp)
	{
		if (strcmp("cd", tmp->av[0]) == 0)
		{
			if (tmp->size < 2)
				exit_cd_1();
			else if (chdir (tmp->av[1]))
				exit_cd_2(tmp->av[1]);
		}
		else
			exec_cmd(tmp, env);
		tmp = tmp->next;
	}
}

void	free_all(t_all *ptr)
{
	t_all 	*tmp;
	int		i;

	while (ptr)
	{
		tmp = ptr->next;
		i = 0;
		while (i < ptr->size)
			free(ptr->av[i++]);
		free(ptr->av);
		free(ptr);
		ptr = tmp;
	}
	ptr = NULL;
}

/*
int main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac == 1)
		return (0);
	else
	{
		while (i < ac)
		{
			printf("Strlen : %d\n", ft_strlen(av[i]));
			printf("Dup : %s\n", ft_strdup(av[i]));
			printf("\n");
			i++;
		}
	}
}
*/

int main(int ac, char **av, char **env)
{
	t_all *ptr = NULL;
	int i;

	i = 1;
	if (ac > 1)
	{
		while (av[i])
    	{
            if (strcmp(av[i], ";") == 0)
            {
                i++;
                continue ;
            }
    	    i += parser_av(&ptr, &av[i]);
    	    if (!av[i])
    	        break;
    	    else
    	        i++;
    	}
	while (ptr)
	{
		
		printf("=================\n");
		for (i = 0; i < ptr->size; i++)
			printf("%s\n", ptr->av[i]);
		printf("TYPE: %d\n", ptr->type);
		printf("SIZE: %d\n", ptr->size);
		printf("=================\n");
		ptr = ptr->next;
	}
	(void)**env;
	printf("END\n");
		if (ptr)
			exec_cd(ptr, env);
		free_all(ptr);
	}
	return (0);
}
