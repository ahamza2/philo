/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:31:54 by haarab            #+#    #+#             */
/*   Updated: 2023/06/20 00:55:42 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void siiiiiii(t_vars *philo)
{
	while (philo->amount_of_food != 0)
	{
		pthread_mutex_lock(&philo->info->fork[philo->fork_right]);
		ft_print(philo ,"has taken a fork");
		pthread_mutex_lock(&philo->info->fork[philo->fork_left]);
		ft_print(philo ,"has taken a fork");
		// pthread_mutex_lock(&philo->info->print);
		ft_print(philo ,"is eating");
		philo->amount_of_food--;
		// pthread_mutex_unlock(&philo->info->print);
		pthread_mutex_lock(&philo->info->print);
		philo->akhir_makla = ft_time();
		pthread_mutex_unlock(&philo->info->print);
		sleeeeep (philo->info->time_to_eat);
		pthread_mutex_unlock(&philo->info->fork[philo->fork_right]);
		pthread_mutex_unlock(&philo->info->fork[philo->fork_left]);
		ft_print(philo ,"is sleeping");
		sleeeeep(philo->info->time_to_sleep);
		ft_print(philo ,"is thinking");
	}
}

void	*routine(void *args)
{
	t_vars *philo;
	philo = (t_vars *)args;
	if (philo->id % 2 == 0)
	{
		sleeeeep(philo->info->time_to_eat);
	}
	// else if (philo->id % 2 == 0 &&)
		// printf ("str ==== %ld\n", philo->info->time_to_eat);
		// sleep (1);
		// usleep (100);
		// ft_print(philo ,"is thinking");
	siiiiiii(philo);
	
	return (NULL);
}