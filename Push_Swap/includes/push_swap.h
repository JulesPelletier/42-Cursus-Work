/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:23:00 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 15:15:50 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct s_push_swap
{
	int			flag[5];
	int			count;
	int			fd;
	char		*list;
	char		*str;
	size_t		size;
	t_stack		stA;
	t_stack		stB;
	int			count_ra;
	int			count_rra;
	int			count_rb;
	int			count_rrb;
	int			ac_dup;
	char		**av_dup;
}				t_push_swap;

void	init_stack(t_stack *stack);
void	all_init2(t_push_swap *all, char **argv);
void	all_init(char **av, t_push_swap *all);
int		check_int(char *str);
int		check_options(t_push_swap *all, int ac, char **av, int i);
int		check_doublons(t_push_swap *all, t_stack *stack);
int		check_borne(t_stack *stack, int min, int max);
void	freechar(char **av);
int		ft_clear(char *str, char *str2, int s);
int		ft_clear2(t_push_swap *all);
void	ft_error2(char *str);
void	ft_error(char *str, t_push_swap *all);
char	**malloqueur(char **av);
char	**replace(char **av, t_push_swap *all);
char	**ft_show(char **str, t_push_swap *all);
char	**all_char(int ac, char **av, t_push_swap *all);
void	function_add(t_push_swap *all);
int		swap(t_stack *stack);
int		push(t_stack *d, t_stack *s);
int		rotate(t_stack *s);
int		reverserotate(t_stack *stack);
int		ft_lecteur(char *inst, t_push_swap *all);
int		get_inf(t_stack *s, size_t i, int value);
int		get_sup(t_stack *s, size_t i, int value);
int		get_median(t_stack *stack);
void	stack_update(t_stack *s, int i);
void	update_output(t_push_swap *game, char *str);
size_t	check_value(t_stack *stack, int n);
int		check_first_a(t_push_swap *all, int n);
int		check_first_b(t_push_swap *all, int n);
int		minormax(t_push_swap *all);
void	new_min(t_push_swap *g, size_t count);
void	fullpushb(t_push_swap *all);
void	bborneur(t_push_swap *all, int bornemin, int bornemax);
void	aborneur(t_push_swap *all, int bornemin, int bornemax);
void	end_str(t_push_swap *all, char *tmp, int i, int j);
int		is_sorted(t_push_swap *all);
int		is_already_sorted(t_push_swap *all);
int		*read_arg(int ac, char **av, int n);
void	algo_check(t_push_swap *all);
void	algo_quinze_plus(t_push_swap *all);
void	algo_quinze(t_push_swap *all);
void	algo_three(t_push_swap *all);
char	*optirr(t_push_swap *all, char *str, char *str2);
char	*optirrr(t_push_swap *all, char *str, char *str2);
char	*gestrr(t_push_swap *all, char *str, char *str2);

#endif
