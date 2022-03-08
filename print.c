/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:27:23 by macbook           #+#    #+#             */
/*   Updated: 2021/12/03 15:37:23 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print(t_philo *philo, int state, unsigned long long time_ms)
{
	if (pthread_mutex_lock(&philo->args->write))
		return (1);
	if (state == THINK)
		printf("%llums|id[%d]|state[thinking...]\n", time_ms, philo->id + 1);
	if (state == SLEEP)
		printf("%llums|id[%d]|state[sleeping...]\n", time_ms, philo->id + 1);
	if (state == FORK)
		printf("%llums|id[%d]|state[taking a fork]\n", time_ms, philo->id + 1);
	if (state == EAT)
		printf("%llums|id[%d]|state[eating ...]\n", time_ms, philo->id + 1);
	if (state == DIE)
	{
		printf("%llums|id[%d]|state[died !!!]\n", time_ms, philo->id + 1);
		return (1);
	}
	if (pthread_mutex_unlock(&philo->args->write))
		return (1);
	return (0);
}
