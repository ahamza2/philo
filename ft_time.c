/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:50:51 by haarab            #+#    #+#             */
/*   Updated: 2023/06/04 20:46:38 by haarab           ###   ########.fr       */
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
	{
		usleep(ti / 10);
	}
}

int ft_deadphilo(t_vars *philo, int time)
{
	// int id;
	while (philo->info->time_to_dead <= philo->info->time_to_eat + philo->info->time_to_sleep)
	{
		time = ft_time() - philo->info->time_to_start;
		if (time >= philo->info->time_to_dead)
		{
			return (time);
		}
	}
	return (0);
}