/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:25:09 by macbook           #+#    #+#             */
/*   Updated: 2021/12/03 15:40:50 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

typedef struct s_arg
{
	int						nb_philo;
	unsigned long long		time_to_die;
	unsigned long long		time_to_eat;
	unsigned long long		time_to_sleep;
	int						nb_of_meals;
	unsigned long long		current_time;
	int						philo_full;
	pthread_mutex_t			*fork;
	pthread_mutex_t			write;
	pthread_mutex_t			is_eating;
}				t_arg;

typedef struct s_philo
{
	pthread_t			tr;
	int					id;
	int					nb_of_meals;
	int					eat;
	unsigned long long	start_time;
	int					left;
	int					right;
	unsigned long long	last_time_eat;
	t_arg				*args;

}				t_philo;

int					ft_atoi(const char *str);
void				init_mutex(t_arg *arg);
void				*work(void	*philo_struct);
int					parsing_data(int ac, char **av, t_arg *args);
t_philo				*init_philo(t_arg *args);
unsigned long long	time_passed(unsigned long long start_time);
unsigned long long	time_now(void);
void				sleepu(unsigned long long end);
int					print(t_philo *philo, int state,
						unsigned long long time_ms);
int					creator(t_philo *philo, t_arg *args);
#endif