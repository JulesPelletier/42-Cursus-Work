/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:35:22 by Jules             #+#    #+#             */
/*   Updated: 2021/09/01 10:34:40 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_params
{
	int		n_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		n_loop;
}				t_params;

typedef struct	s_philo
{
	int		number;
	pid_t	process;
	int		f_left;
	int		f_right;
	int		is_eating;
	int		count_eat;

}				t_philo;

typedef struct s_all
{
	t_params	params;
	t_philo		*philos;
}				t_all;

int		ft_atoi(const char *str);

void	init_params(t_all *all);
void	init_philo(t_philo philo, int i);
void	parse_params(t_all *all, int ac, char **av);
void	create_philos(t_all *all);

//CHECKS

void	show_struct(t_all *all);
void	show_philos(t_all *all);

#endif 