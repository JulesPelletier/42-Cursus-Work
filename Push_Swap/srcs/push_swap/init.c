/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:52:05 by Jules             #+#    #+#             */
/*   Updated: 2021/07/24 17:53:49 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    init_stack(t_stack *stack)
{
	size_t	i;

	i = 1;
	if (stack->len == 0)
		return ;
	stack->first = stack->st[stack->len - 1];
	stack->second = stack->st[0];
	stack->min = stack->second;
	stack->max = stack->second;
	while (i < stack->len)
	{
		if (stack->st[(int)i] > stack->max)
			stack->max = stack->st[(int)i];
		if (stack->st[(int)i] < stack->min)
			stack->min = stack->st[(int)i];
		i++;
	}
}

void	all_init2(t_push_swap *all, char **av)
{
	all->stA.st = read_arg(all->ac_dup, av, all->count);
	all->size = all->ac_dup - all->count - 1;
	all->stA.len = all->size;
	all->stA.flag = 0;
	all->stB.flag = 1;
	all->stB.st = malloc(sizeof(int) * all->stA.len);
	if (!(all->stB.st))
		ft_error("2", all);
}

void	all_init(char **av, t_push_swap *all)
{
	int		i;

	all->count_ra = 0;
	all->count_rra = 0;
	all->count_rb = 0;
	all->count_rrb = 0;
	i = 0;
	while (i < 4)
		all->flag[i++] = 0;
	all->str = malloc(sizeof(char) * 1);
	if (!(all->str))
		ft_error2("malloc");
	*all->str = '\0';
	all->fd = 1;
	if (!check_options(all, all->ac_dup, av, 1))
	{
		free(all->str);
		ft_error("1", all);
	}
	all_init2(all, av);
}