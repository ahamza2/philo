/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:26:29 by haarab            #+#    #+#             */
/*   Updated: 2023/06/20 21:07:31 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_thread(t_var *info)
{
	int	i;

	i = 0;
	while (i < info->nbr_philo)
	{
		if (pthread_mutex_init(&info->fork[i], NULL) != 0)
			return ;
		i++;
	}
	pthread_mutex_init(&info->print, NULL);
}

void	init_struct(t_var *info, t_vars *philo, int ac, char **av)
{
	long	t;
	int		i;

	t = ft_time();
	i = 0;
	while (i < info->nbr_philo)
	{
		philo[i].fork_left = (i + 1) % info->nbr_philo;
		philo[i].fork_right = i;
		philo[i].akhir_makla = t;
		if (ac == 6)
			philo[i].amount_of_food = ft_atoi(av[5]);
		else
			philo[i].amount_of_food = -1;
		philo[i].info = info;
		philo[i].id = i + 1;
		philo[i].is_dead = 1;
		if (pthread_create(&philo[i].philo, NULL, &routine, &philo[i]) != 0)
			return ;
		i++;
	}
}

void	destroy_mutex(t_vars *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->nbr_philo)
	{
		if (pthread_mutex_destroy(&philo->info->fork[i]) != 0)
			return ;
		i++;
	}
	if (pthread_mutex_destroy(&philo->info->print) != 0)
		return ;
}

void	join_threads(t_vars *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->nbr_philo)
	{
		if (pthread_join(philo[i].philo, NULL) != 0)
			return ;
		i++;
	}
}
