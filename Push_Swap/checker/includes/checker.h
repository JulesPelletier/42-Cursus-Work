/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:23:44 by Jules             #+#    #+#             */
/*   Updated: 2022/01/07 13:43:11 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHECKER_H_
# define _CHECKER_H_

# include "../Libft/libft.h"
# include "../GNL/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_stack
{
	int			*st;
	size_t		len;
	int			max;
	int			min;
	int			first;
	int			second;
	int			flag;
	int			fsort;
	int			fmax;
}				t_stack;

typedef struct s_checker
{
	int			flag[7];
	int			count;
	int			fd;
	char		*str;
	size_t		len;
	t_stack		stA;
	t_stack		stB;
}				t_checker;

int	swap(t_stack *stack);
int	push(t_stack *d, t_stack *s);
int	rotate(t_stack *s);
int	reverserotate(t_stack *stack);
int	ft_lecteur(char *inst, t_checker *all);
int	ft_exit(char *str);
void	stack_update(t_stack *s, int i);


#endif