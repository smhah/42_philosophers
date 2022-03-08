/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:22:19 by macbook           #+#    #+#             */
/*   Updated: 2021/12/03 15:42:01 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_not_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_errors(char **av, int ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_not_digit(av[i]))
			return (1);
		if (ft_atoi(av[i]) < 0)
			return (1);
		i++;
	}
	return (0);
}

int	parsing_data(int ac, char **av, t_arg *args)
{
	if (check_errors(av, ac))
	{
		printf("Error\n");
		return (0);
	}
	args->nb_philo = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		args->nb_of_meals = ft_atoi(av[5]);
	else
		args->nb_of_meals = -1;
	return (1);
}
