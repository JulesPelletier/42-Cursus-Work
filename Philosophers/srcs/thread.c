/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:50:02 by Jules             #+#    #+#             */
/*   Updated: 2021/09/07 19:01:00 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		get_chrono(void)
{
	struct timeval		tv;
	int		i;

	gettimeofday(&tv, NULL);
	printf("Sec : %ld | Usec : %d\n", tv.tv_sec, tv.tv_usec);
	i = tv.tv_sec + tv.tv_usec;
	return (i);
}

void	*algo(void *arg)
{
	t_philo	*philo;

	philo = arg;
	return (NULL);
}

void	*is_dead(void *args)
{
	printf("Dead\n");
	return (NULL);
}

int	thread_init(t_all *all)
{
	int			i;
	pthread_t	th;

	i = 0;
	all->time = get_chrono();
	//printf("Time : %lf ms \n", (int)all->time);
	while (i < all->params.n_philo)
	{
		all->philos[i].time = all->time - get_chrono();
		//printf("Philos : %lf ms \n", (int)(all->time - all->philos[i].time));
		if (pthread_create(&th, NULL, algo, (void *)&all->philos[i]))
			return (1);
		pthread_detach(th);
		if (pthread_create(&all->philos[i].thread, NULL, is_dead,
			(void *)&all->philos[i]))
			return (1);
		usleep(1000);
		i++;
	}
	i = 0;
	while (i < all->params.n_philo)
		pthread_join(*all->philos[i++].thread, NULL);
	return (0);
}