/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:35:22 by Jules             #+#    #+#             */
/*   Updated: 2021/12/05 16:59:22 by julpelle         ###   ########.fr       */
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

typedef struct s_params		t_params;
typedef struct s_philo		t_philo;
typedef struct s_all		t_all;

struct s_params
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_loop;
	long int		start;
	int				count_philos;
	int				end;
	pthread_mutex_t	died;
	pthread_mutex_t	eating;
	pthread_mutex_t	print;
	pthread_mutex_t	finished;
};

struct s_philo
{
	int				number;
	long int		t_last_meal;
	int				finish;
	int				count_eat;
	pthread_t		thread;
	pthread_t		thread_dead;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	t_params		*params;
};

struct s_all
{
	t_philo			*philos;
	t_params		params;
};


int			ft_atoi(const char *str);
void		ft_putchar_fd(char c, int fd);
int			ft_isdigit(int c);
int			ft_isdigit_str(char *str);
int			ft_strlen(char *str);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *str, int fd);
int			ft_exit(char *str, int fd);
long int	get_chrono(void);
int			ft_parse(int ac, char **av, t_params *params);
void		init_mutex(t_all *all);
int			init_all(t_all *all);
int			init_loop(t_all *all);
void		display_text(char *str, t_philo *ph);
void		routine(t_philo *ph);
int			check_death_philo(t_philo *ph, int i);
int			check_death_all(t_all *all);
void		ft_wait(long int time);
void		*is_dead(void *ptr);
void		*threads(void *ptr);
int			loop(t_all *all);
void		ft_sleep(t_philo *philo);
void		ft_think(t_philo *philo);
void		ft_eating(t_philo *philo);
void		ft_take_a_fork(t_philo *philo);
void		ft_is_dead(t_philo *philo);
void		routine(t_philo *philo);
int			check_args(char **av);
int			check_number(char *str);
int			check_numberofargs(int ac);
int			check_params(int ac, char **av);
void		end_loop(t_all *all);
void		show_struct(t_all *all);
void		show_game(t_all *all);
void		show_philos(t_all *all);
void		show_ate(t_all *all);
void		show_all(t_all *all);

#endif
