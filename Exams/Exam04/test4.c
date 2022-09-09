/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:15:30 by julpelle          #+#    #+#             */
/*   Updated: 2022/06/09 15:36:46 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

# define STDIN	0
# define STDOUT	1
# define STDERR	2

# define TYPE_PIPE	3
# define TYPE_BREAK	4
# define TYPE_END	5

typedef struct	s_base
{
	int size;
	int fd[2];
	int type;
	char **av;
	struct s_base	*next;
	struct s_base	*prev;
}				t_base;

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
	int i;
	int size;
	char *res;

	size = ft_strlen(str);
	i = 0;
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	size_arg(char **av)
{
	int i;

	i = 0;
	while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
		i++;
	return (i);
}

int check_end(char *str)
{
	if (!str)
		return (TYPE_END);
	if (strcmp(str, "|") == 0)
		return (TYPE_PIPE);
	if (strcmp(str, ";") == 0)
		return (TYPE_BREAK);
	return (0);
}

void	ft_lst_addback(t_base **ptr, t_base *new)
{
	t_base *tmp;
	
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

int	parse_arg(t_base **ptr, char **av)
{
	int size;
	int i;
	t_base *new;

	size = size_arg(av);
	new = (t_base *)malloc(sizeof(t_base))
	if (!new)
		exit();
	new->av = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new->av)
		exit();
	new->next = NULL;
	new->prev = NULL;
	new->size = size;
	i = 0;
	while (i < size)
	{
		new->av[i] = ft_strdup(av[i]);
		i++;
	}
	new->av[i] = NULL;
	new->type = check_end(new->av[i]);
	ft_lst_addack(ptr, new);
	return (new->size);
}

void	exec_cmd(t_base *tmp, char **env)
{
	int status;
	int pipe_open;
	pid_t	pid;
	
	pipe_open = 0;
	if (tmp->type == TYPE_PIPE || (tmp->prev && tmp->prev->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(tmp->fd))
			exit();
	}
	pid = fork();
	if (pid < 0)
		exit();
	if (pid == 0)
	{
		if (tmp->type == TYPE_PIPE && dup2(tmp->fd[STDOUT], STDOUT) < 0)
			exit();
		if (tmp->prev && tmp->prev->type == TYPE_PIPE && dup2(tmp->prev->fd[STDIN], STDIN) < 0)
			exit();
		if (execve(tmp->av[0], tmp->av, env) < 0)
			exit();
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
			close(tmp->prev->fd[STDIN]);
	}
}

void	exec_cd(t_base *ptr, char **env)
{
	t_base *tmp;

	tmp = ptr;
	while (tmp)
	{
		if (strcmp(tmp->av[0], "cd") == 0)
		{
			if (tmp->size < 2)
				exit();
			else if (chdir(tmp->av[1]) < 0)
				exit();
		}
		else
			exec_cmd(tmp, env);
		tmp = tmp->next;
	}
}

void	free_all(t_base *ptr)
{
	t_base *tmp;
	int		i;

	while (ptr)
	{
		i = 0;
		tmp = ptr->next;
		while (i < ptr->size)
			free(ptr->av[i]);
		free(ptr->av);
		free(ptr);
		ptr = tmp;
	}
	ptr = NULL;
}

int main(int ac, char **av, char **env)
{
	int i;
	t_base *ptr;

	ptr = NULL;
	i = 0;
	if (ac > 1)
	{
		while (av[i])
		{
			if (strcmp(av[i], ";") == 0)
			{
				i++;
				continue;
			}
			i += parse_arg(&ptr, &av[i]);
			if (!av[i])
				break;
			else
				i++;
		}
		if (ptr)
			exec_cd(ptr, env);
		free_all(ptr);
	}
	return (0);
}