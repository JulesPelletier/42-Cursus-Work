/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:23:44 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 15:14:33 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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
	int			ac_dup;
	char		**av_dup;
}				t_checker;

int		*init_stack(int ac, char **av, int count);
void	checker_init(t_checker *all, int i);
int		check_op(char *line, char **action);
int		check_int(char *nbr);
int		check_options(int ac, char **av, t_checker *all, int count2);
int		check_sorted(t_checker *all);
int		doublon_int(t_stack *stack);
char	**createaction3(char **action);
char	**createaction2(char **action);
char	**createaction(void);
void	swap(t_stack *stack);
void	push(t_stack *stack1, t_stack *stack2);
void	rotate(t_stack *stack);
void	revrotate(t_stack *stack);
void	operations_menu(char *inst, t_checker *all);
void	optionv2(t_checker *all);
void	optionv(t_checker *all, char **action, int *list, int count);
int		*listeur(int *list, int len, char *line, char **action);
void	freeaction(char **action, char *line, int *list);
void	applications(int *list, t_checker *all, char **action, int len);
void	ft_ch(t_checker *all, int len, char **action);
void	freechar(char **av);
char	**malloqueur(char **av);
char	**replace(char **av, t_checker *all);
char	**ft_show(char **str, t_checker *all);
char	**all_char(int ac, char **av, t_checker *all);
void	ft_stop5(void);
void	ft_stop4(char *str, t_checker *all);

#endif
