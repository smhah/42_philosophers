/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_job.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:34:41 by macbook           #+#    #+#             */
/*   Updated: 2021/12/03 15:45:11 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_philo *philo)
{
	unsigned long long	befaure_sleep;
	unsigned long long	current_time;

	print(philo, SLEEP, time_passed(philo->start_time));
	befaure_sleep = time_now();
	usleep(philo->args->time_to_sleep * 1000 - 10000);
	current_time = time_passed(befaure_sleep);
	sleepu(befaure_sleep + philo->args->time_to_sleep);
	current_time = time_passed(current_time);
}

void	continue_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->is_eating);
	philo->last_time_eat = time_now();
	pthread_mutex_unlock(&philo->args->is_eating);
	print(philo, EAT, time_passed(philo->start_time));
	philo->eat = 1;
	usleep(philo->args->time_to_eat * 1000 - 10000);
	sleepu(philo->last_time_eat + philo->args->time_to_eat);
	pthread_mutex_lock(&philo->args->is_eating);
	philo->nb_of_meals++;
	philo->eat = 0;
	if (philo->nb_of_meals == philo->args->nb_of_meals)
	{
		philo->args->philo_full++;
	}
	pthread_mutex_unlock(&philo->args->is_eating);
}

void	eat(t_philo *philo)
{
	int	right;
	int	left;

	if (philo->id % 2 == 0)
	{
		right = (philo->id + 1) % philo->args->nb_philo;
		left = philo->id;
	}
	else
	{
		right = philo->id;
		left = (philo->id + 1) % philo->args->nb_philo;
	}
	pthread_mutex_lock(&philo->args->fork[right]);
	print(philo, FORK, time_passed(philo->start_time));
	pthread_mutex_lock(&philo->args->fork[left]);
	print(philo, FORK, time_passed(philo->start_time));
	continue_eating(philo);
	pthread_mutex_unlock(&philo->args->fork[right]);
	pthread_mutex_unlock(&philo->args->fork[left]);
}

void	think(t_philo *philo)
{
	print(philo, THINK, time_passed(philo->start_time));
}

void	*work(void	*philo_struct)
{
	t_philo	*philo;

	philo = (t_philo *)philo_struct;
	while (philo->args->nb_of_meals)
	{
		eat(philo);
		ft_sleep(philo);
		think(philo);
	}
	return (NULL);
}
