/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:35:22 by Jules             #+#    #+#             */
/*   Updated: 2021/12/04 20:54:21 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

typedef struct s_params	t_params;
typedef struct s_philo	t_philo;
typedef struct s_all	t_all;


typedef struct s_params
{
	int		n_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		n_loop;
}				t_params;

typedef struct s_philo
{
	int				number;
	pthread_mutex_t	f_left;
	pthread_mutex_t	*f_right;
	int				count_eat;
	long int		t_last_meal;
	int				finish;
	pthread_t		thread;
	pthread_t		thread_id;
	t_all			*all;

}				t_philo;

typedef struct s_all
{
	int				finish;
	long int		t_start;
	long int		time;
	int				count_eat;
	pthread_mutex_t	text;
	pthread_mutex_t	finished;
	pthread_mutex_t	eating;
	pthread_mutex_t	died;
	t_params		params;
	t_philo			*philos;
}				t_all;

int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *str, int fd);
int		ft_exit(char *str, int fd);

int		check_args(char **av);
int		check_number(char *str);
int		check_numberofargs(int ac);
int		check_params(int ac, char **av);
int		check_end(t_philo *philo, int i);

void	init_params(t_all *all);
t_philo	set_philo(t_all *all, t_philo philo, int i);
void	init_philo(t_all *all);
void	init_all(t_all *all, int ac, char **av);
void	init_mutex(t_all *all);

void	parse_params(t_all *all, int ac, char **av);
void	create_philos(t_all *all);
int		get_chrono(void);
void	ft_my_usleep(long int time);

void	is_sleeping(t_all *all, t_philo *philo);
void	is_eating(t_all *all, t_philo *philo);
void	no_fork(t_all *all, t_philo *philo);
void	fork_lock(t_all *all, t_philo *philo);

int		start_loop(t_all *all);
void	*test(void *arg);
void	display_text(int time, t_philo philo, int i);
int		clean_threads(t_all *all);


void	*philo_died(void *ptr);
int	launch_loop(t_all *all);
void	*loop(void *ptr);



//CHECKS

void	show_struct(t_all *all);
void	show_philos(t_all *all);
void	show_game(t_all *all);
void	show_all(t_all *all);
void	show_philos2(t_philo *philos);
void	show_ate(t_all *all);

#endif 