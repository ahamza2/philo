/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:50:51 by haarab            #+#    #+#             */
/*   Updated: 2023/06/17 23:54:25 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int ft_time(void)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000L) + (time.tv_usec / 1000L);
}


void sleeeeep(long ti)
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
	int all_eat = 0;
	while (i < philo->info->nbr_philo)
	{
		int j = 0;
		while (j < philo->info->nbr_philo)
		{
			if (philo[j].amount_of_food == philo->info->number_meal)
				all_eat++;
			j++;	
		if (all_eat == philo->info->nbr_philo)
				return 1;
		}
	
		if (time >= philo->info->time_to_dead)
		{
			int j = 0;
			while (j < philo->info->nbr_philo)
			{
				philo[j].is_dead = 0;
				j++;
			}
			pthread_mutex_lock(&philo->info->print);
			printf("%ld %d is died\n", ft_time() - philo->info->time_to_start, philo[i].id);
			pthread_mutex_unlock(&philo->info->print);
			return 1;
		}
		pthread_mutex_lock(&philo->info->print);
		time = ft_time() - philo[i].akhir_makla;
		pthread_mutex_unlock(&philo->info->print);
		i++;
	}
	return 0;
}

// int ft_food(t_vars *philo)
// {
// 	int i = 0;
	
// 	while (i < philo->info->nbr_philo)
// 	{
// 		if (0 == philo[i].amount_of_food)
// 		{
// 			int j = 0;
// 			while (j < philo->info->nbr_philo)
// 			{
// 				philo[j].amount_of_food = 0;
// 				j++;
// 			}
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);

// }