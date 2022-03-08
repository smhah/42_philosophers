/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:01:55 by smhah             #+#    #+#             */
/*   Updated: 2021/12/03 15:45:52 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_meals(t_philo *philo, int *k, t_arg *args)
{
	if (philo->args->nb_philo != -1)
	{
		if ((args->philo_full == args->nb_philo
				&& philo->eat == 0) || args->nb_of_meals == 0)
		{
			*k = 0;
			return (0);
		}
	}
	return (1);
}

int	creator(t_philo *philo, t_arg *args)
{
	int	i;
	int	k;

	k = 1;
	if (args->nb_of_meals)
	{
		while (k)
		{
			i = 0;
			while (i < args->nb_philo && !philo[i].eat)
			{
				if (!check_meals(&philo[i], &k, args))
					break ;
				if (philo[i].eat == 0 && time_passed(philo[i].last_time_eat)
					> args->time_to_die)
				{
					print(&philo[i], DIE, time_passed(philo[i].start_time));
					k = 0;
					break ;
				}
				i++;
			}
		}
	}
	return (0);
}
