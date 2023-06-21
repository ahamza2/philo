/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:31:54 by haarab            #+#    #+#             */
/*   Updated: 2023/06/21 19:28:07 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	time_last_eat(t_vars *philo)
{
	pthread_mutex_lock(&philo->info->print);
	philo->time_last_eat = ft_time();
	pthread_mutex_unlock(&philo->info->print);
}

void	check_rotine(t_vars *philo)
{
	while (philo->amount_of_food != 0)
	{
		pthread_mutex_lock(&philo->info->print);
		if (philo->is_dead == 0)
		{
			pthread_mutex_unlock(&philo->info->print);
			return ;
		}
		pthread_mutex_unlock(&philo->info->print);
		pthread_mutex_lock(&philo->info->fork[philo->fork_right]);
		ft_print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->info->fork[philo->fork_left]);
		ft_print(philo, "has taken a fork");
		ft_print(philo, "is eating");
		pthread_mutex_lock(&philo->info->print);
		philo->amount_of_food--;
		pthread_mutex_unlock(&philo->info->print);
		time_last_eat(philo);
		sleeeeep(philo->info->time_to_eat);
		pthread_mutex_unlock(&philo->info->fork[philo->fork_right]);
		pthread_mutex_unlock(&philo->info->fork[philo->fork_left]);
		ft_print(philo, "is sleeping");
		sleeeeep(philo->info->time_to_sleep);
		ft_print(philo, "is thinking");
	}
}

void	*routine(void *args)
{
	t_vars	*philo;

	philo = (t_vars *) args;
	if (philo->id % 2 == 0)
	{
		sleeeeep(philo->info->time_to_eat);
	}
	check_rotine(philo);
	return (NULL);
}
