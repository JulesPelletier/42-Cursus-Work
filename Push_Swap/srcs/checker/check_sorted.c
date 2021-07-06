/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:40:12 by Jules             #+#    #+#             */
/*   Updated: 2021/04/29 10:03:15 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ft_heapsort_recursive(t_all *all, int n, int i)
{
    int     largest;
    int     left;
    int     right;
    int     tmp;

    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;
    tmp = 0;
    if (left < n && all->stA.stack[left] > all->stA.stack[largest])
        largest = left;
    if (right < n && all->stA.stack[right] > all->stA.stack[largest])
        largest = right;
    if (largest != i)
    {
        tmp = all->stA.stack[i];
        all->stA.stack[i] = all->stA.stack[largest];
        all->stA.stack[largest] = tmp;
        ft_heapsort_recursive(all, n, largest);
    }
}

void    ft_swap(int a, int b)
{
    int     tmp;

    tmp = a;
    a = b;
    b = tmp;
}

void    ft_heapsort(t_all *all)
{
    int     i;

    i = all->stA.len / 2 - 1;
    while (i >= 0)
    {
        ft_heapsort_recursive(all, all->stA.len, i);
        i--;
    }
    i = all->stA.len - 1;
    while (i > 0)
    {
        ft_swap(all->stA.stack[0], all->stA.stack[i]);
        ft_heapsort_recursive(all, i, 0);
        i--;
    }
}

int     ft_check_sort(t_all *all)
{
    int     i;

    i = 0;
    if (all->stB.len == 0)
    {
        while (i < all->stA.len && i + 1 < all->stA.len)
        {
            if (all->stA.stack[i] > all->stA.stack[i + 1])
                return (0);
            else
                i++;
        }
        return (1);
    }
    return (0);
}