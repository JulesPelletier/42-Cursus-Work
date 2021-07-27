/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 20:06:09 by Jules             #+#    #+#             */
/*   Updated: 2021/07/27 17:55:29 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	optionv2(t_checker *all)
{
	int		i;

	printf(" \n");
	printf("%11c   %-11c\n", 'a', 'b');
	i = (int)all->stA.len - 1;
	while (i >= 0)
	{
		if (i < (int)all->stA.len)
			printf("%11d | ", all->stA.st[i]);
		else
			printf("%11s | ", "");
		if (i < (int)all->stB.len)
			printf("%-11d", all->stB.st[i]);
		printf("\n");
		i--;
	}
	usleep(300000);
}

void	optionv(t_checker *all, char **action, int *list, int count)
{
	if (all->flag[5] == 1)
	{
		printf("\e[H\e[2J");
		printf("---%d-----\n", count + 1);
		return ;
	}
	if (all->flag[1] != 1)
		return ;
	printf("\e[H\e[2J");
	printf("---%d-----\n", count + 1);
	if (all->flag[0] == 1)
		printf("\e[1;34m%s\e[0m", action[list[count]]);
	else
		printf("%s", action[list[count]]);
	while (count > 0)
		printf(" %s", action[list[count--]]);
	optionv2(all);
}
