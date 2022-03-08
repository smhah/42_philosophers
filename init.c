/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:17:43 by macbook           #+#    #+#             */
/*   Updated: 2021/12/03 15:42:38 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_arg *arg)
{
	int		i;

	i = 0;
	arg->fork = malloc(sizeof(pthread_mutex_t) * arg->nb_philo);
	while (i < arg->nb_philo)
		pthread_mutex_init(&arg->fork[i++], NULL);
	pthread_mutex_init(&arg->write, NULL);
}

t_philo	*init_philo(t_arg *args)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * args->nb_philo);
	while (i < args->nb_philo)
	{
		philo[i].args = args;
		philo[i].eat = 0;
		philo[i].id = i;
		philo[i].nb_of_meals = 0;
		philo[i].last_time_eat = time_now();
		philo[i].start_time = philo[i].last_time_eat;
		i++;
	}
	return (philo);
}
