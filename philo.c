/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:17:48 by macbook           #+#    #+#             */
/*   Updated: 2021/12/03 15:44:46 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_args(t_arg *args)
{
	printf("number of philo is [%d]\n", args->nb_philo);
	printf("time to die is [%llu]\n", args->time_to_die);
	printf("time to eat is [%llu]\n", args->time_to_eat);
	printf("time to sleep is [%llu]\n", args->time_to_sleep);
	printf("number of meals is [%d]\n", args->nb_of_meals);
	args->philo_full = 0;
}

void	litsgoo(t_arg *args)
{
	int			i;
	t_philo		*philo;

	philo = init_philo(args);
	i = 0;
	init_mutex(args);
	while (i < args->nb_philo)
	{
		if (pthread_create(&philo->tr, NULL, work, &philo[i]))
			printf("Error\n");
		usleep(100);
		i++;
	}
	creator(philo, args);
}

int	main(int ac, char **av)
{
	t_arg	*args;

	if (ac == 5 || ac == 6)
	{
		args = malloc(sizeof(t_arg));
		if (!parsing_data(ac, av, args))
			return (0);
		litsgoo(args);
	}
	else
		printf("Error\n");
	return (1);
}
