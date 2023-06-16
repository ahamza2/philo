/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:50:51 by haarab            #+#    #+#             */
/*   Updated: 2023/06/16 23:10:05 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int ft_time(void)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000L) + (time.tv_usec / 1000L);
}


void sleeeeep(long ti, t_vars __attribute__((unused)) *philo)
{
	long time;
	time = ft_time();
	while (ft_time() - time < ti)
		usleep (ti / 10);
}

int ft_deadphilo(t_vars *philo)
{
	long time;
	int i = 0;
	while (i < philo->info->nbr_philo)
	{
		pthread_mutex_lock(&philo->info->print);
		time = ft_time() - philo[i].akhir_makla;
		pthread_mutex_unlock(&philo->info->print);
		if (time >= philo->info->time_to_dead)
		{
			int j = 0;
			while (j < philo->info->nbr_philo)
			{
				philo[j].is_dead = 0;
				j++;
			}
			pthread_mutex_lock(&philo->info->print);
			printf("%ld %d is deid\n", ft_time() - philo->info->time_to_start, philo[i].id);
			pthread_mutex_unlock(&philo->info->print);
			return 1;
		}
		i++;
	}
	return 0;
}

int ft_food(t_vars *philo)
{
	int i;

	i = 0;
	while (i < philo->info->nbr_philo)
	{
		if (philo->amount_of_food == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}