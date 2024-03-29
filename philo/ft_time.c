/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:50:51 by haarab            #+#    #+#             */
/*   Updated: 2023/06/21 22:31:24 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000L) + (time.tv_usec / 1000L));
}

void	sleeeeep(long ti, t_vars *philo)
{
	long	time;

	time = ft_time();
	while (ft_time() - time < ti)
	{
		pthread_mutex_lock(&philo->info->print);
		if (philo->info->is_dead == 1)
		{
			pthread_mutex_unlock(&philo->info->print);
			return ;
		}
		pthread_mutex_unlock(&philo->info->print);
		usleep(250);
	}
}
