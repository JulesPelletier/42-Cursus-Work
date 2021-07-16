/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 10:27:48 by Jules             #+#    #+#             */
/*   Updated: 2021/07/09 12:22:07 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


int     main(int ac, char **av)
{
    t_all   all;
    
    ft_init_all(&all);
    if (ac < 2)
        return (0);
    ft_fill_stack(&all, ac, av);
    if (all.err.kill == 1 || ft_check_doublons(all.stA) == 0)
    {
        ft_putstr("Error\n");
        return (0);
    }
    ft_get_median(&all.stA);
    ft_get_max(&all.stA);
    ft_get_min(&all.stA);
    ft_get_divider(&all.stA);
    ft_algo(&all);
    if (all.err.kill == 1)
        ft_putstr("OK\n");
    return (0);
}

/*
void	one_hundred_args(t_all *all)
{
	int	*chunk;
	int	mult;
	int	chunk_len;
	int	pos;

	chunk_len = all->stA.len / 11;
	mult = 1;
	while (all->stA.len > 0 && mult <= 5)
	{
		chunk = get_chunk(a, chunk_len, 0, 1);
		while (all->stB.len < chunk_len * mult && mult <= 5)
		{
			pos = get_pos(a->nbr, all->stA.len, chunk);
			if (pos < 0)
				while (is_in(a->nbr[0], chunk_len, chunk))
					do_rotate(a, 'a');
			else
				while (is_in(a->nbr[0], chunk_len, chunk))
					do_reverse_rotate(a, 'a');
			push_in_good_place(a, b);
		}
		mult++;
		free(chunk);
	}
	push_major(a, b);
}

void    ft_push_swap(t_all *all)
{
    if (all.stA.len == 2)
        ft_options_two(all);

    else if (all.stA.len == 3)
        ft_options_three(all, &all->stA);
    else if (all.stA.len < 100)
		one_hundred_args(all);
	else if (all.stA.len >= 100 && all.stA.len < 2000)
		one_hundred_args(all);
	if (check_sorted(all))
		printf("OK\n");
	else
		printf("KO\n");
}

int     main_2(int ac, char **av)
{
    t_all   all;
    
    ft_init_all(&all);
    if (ac < 2)
        return (0);
    ft_fill_stack(&all, ac, av);
    if (all.err.kill == 1 || ft_check_doublons(all.stA) == 0)
    {
        ft_putstr("Error\n");
        return (0);
    }
    ft_push_swap(all, ac)

    return (0);
}
*/