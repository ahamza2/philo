/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:28:37 by haarab            #+#    #+#             */
/*   Updated: 2023/06/21 18:23:24 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	all_philoaredead(t_vars *philo)
{
	int	j;

	j = 0;
	while (j < philo->info->nbr_philo)
	{
		philo[j].is_dead = 0;
		j++;
	}
}

void	philo_dead(t_vars *philo, int i)
{
	all_philoaredead(philo);
	if (philo->info->nbr_philo == 1)
		pthread_mutex_unlock(&philo->info->fork[0]);
	pthread_mutex_lock(&philo->info->print);
	printf("%ld %d is died\n", ft_time() - philo->info->time_to_start,
		philo[i].id);
	pthread_mutex_unlock(&philo->info->print);
}

int	ft_deadphilo(t_vars *philo)
{
	long	time;
	int		i;
	int		food;

	i = 0;
	while (i < philo->info->nbr_philo)
	{
		pthread_mutex_lock(&philo->info->print);
		time = ft_time() - philo[i].time_last_eat;
		pthread_mutex_unlock(&philo->info->print);
		pthread_mutex_lock(&philo->info->print);
		food = philo->amount_of_food;
		pthread_mutex_unlock(&philo->info->print);
		if (food == 0)
			return (1);
		if (time >= philo->info->time_to_dead)
		{
			philo_dead(philo, i);
			return (1);
		}
		i++;
	}
	return (0);
}
