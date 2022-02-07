/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:41:17 by julpelle          #+#    #+#             */
/*   Updated: 2021/12/06 06:49:16 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <stdbool.h>

# define RESET	"\033[0m"
# define BLACK   "\033[30m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

typedef struct s_params
{
	int			n_philo;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			n_loop;
	int			must_eat;
}	t_params;

typedef struct s_philo
{
	int				number;
	int				count_philo;
	void			*ptr;
	int				fork_available;
	long long int	last_meal;
	pthread_t		thread;
	pthread_mutex_t	m_p_eat;
	pthread_mutex_t	fork;
}	t_philo;

typedef struct s_all
{
	long long int	start;
	int				death;
	int				count_eat;
	int				error;
	t_philo			*philo;
	t_params		params;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	m_a_eat;
	pthread_mutex_t	m_end;
	pthread_mutex_t	m_print;
}	t_all;

int				check_condition(t_all *all, bool just_error);
int				check_count(t_all *all);
int				free_philos(t_all *all);
long long int	get_chrono(t_all *all);
void			init_philos(int nb_p, t_all *all);
void			init_philos(int nb_p, t_all *all);
int				init_loop(t_all *all);
int				parsing(t_params *params, int ac, char **av);
void			display(t_all *all, int i, char *str, long long int duration);
void			*take_fork(t_all *all, int i, bool action, int next);
void			*loop_philo(void *var);
int				check_end_loop(int i, t_all *all);
void			loop(t_all *all, int i);
int				ft_atoi_2(char *av, int *nb);
int				ft_atoi(const char *str);
int				check_number(char *str);
int				check_numberofargs(int ac);
int				check_args(char **av);
int				check_params(int ac, char **av);
int				ft_exit(char *str, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
int				check_av(t_params *params, char **av);

#endif
