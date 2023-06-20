/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:28:37 by haarab            #+#    #+#             */
/*   Updated: 2023/06/20 00:42:12 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_food(t_vars *philo, int all_eat)
{
	int	j;

	j = 0;
	while (j < philo->info->nbr_philo && philo->ac == 6)
	{
		pthread_mutex_lock(&philo->info->print);
		if (philo[j].amount_of_food == philo->info->number_meal)
			all_eat++;
		pthread_mutex_unlock(&philo->info->print);
		j++;
	}
	if (all_eat == 0)
		return (-1);
	return (all_eat);
}

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

int	ft_deadphilo(t_vars *philo)
{
	long time;
	int i;
	int all_eat;

	i = 0;
	all_eat = 0;
	while (i < philo->info->nbr_philo)
	{
		pthread_mutex_lock(&philo->info->print);
		time = ft_time() - philo[i].akhir_makla;
		pthread_mutex_unlock(&philo->info->print);
		if (philo->amount_of_food == 0)
			return (1);
		if (time >= philo->info->time_to_dead)
		{
			all_philoaredead(philo);
			pthread_mutex_lock(&philo->info->print);
			printf("%ld %d is died\n", ft_time() - philo->info->time_to_start,
				philo[i].id);
			pthread_mutex_unlock(&philo->info->print);
			return (1);
		}
		i++;
	}
	return (0);
}