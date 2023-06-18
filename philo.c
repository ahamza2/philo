/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:22:52 by haarab            #+#    #+#             */
/*   Updated: 2023/06/18 23:54:16 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		check_arg(t_vars *philo, char **av)
{
	t_var	*info ;
	int i;
	
	info = malloc(sizeof(t_var));
	info->nbr_philo = ft_atoi(av[1]);
	info->time_to_dead = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (philo->ac == 6)
	{
		info->number_meal = ft_atoi(av[5]);
		if (info->number_meal == 0)
			return ;
	}
	info->fork = malloc(sizeof(pthread_mutex_t) * info->nbr_philo);
	info->time_to_start = ft_time();
	i = 0;
	while (i < info->nbr_philo)
	{
		pthread_mutex_init(&info->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&info->print, NULL);
	long  t = ft_time();
	i = 0;
	while (i < info->nbr_philo)
	{
		philo[i].fork_left = (i + 1) % info->nbr_philo;
		philo[i].fork_right = i;
		philo[i].akhir_makla = t;
		philo[i].amount_of_food = -1;
		philo[i].info = info;
		philo[i].id = i + 1;
		philo[i].is_dead = 1;
		pthread_create(&philo[i].philo, NULL, &routine, &philo[i]);
		i++;
	}
	while (1)
	{
		if (ft_deadphilo(philo) == 1)
			return ;
	}
	i = 0;
	while (i < philo->info->nbr_philo)
	{
		pthread_join(philo[i].philo, NULL);
		i++;
	}
	i = 0;
	while (i < philo->info->nbr_philo)
	{
		pthread_mutex_destroy(&philo->info->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->info->print);
}


int main(int ac, char **av)
{
	// int i;
	
	if (ac < 5 || ac > 6)
	{
		printf ("Error");
		return (0);
	}
	t_vars *philo = NULL;
	philo = malloc(sizeof(t_vars) * ft_atoi(av[1]));
	if (ac == 6)
		philo->ac = ac;
	check_arg(philo, av);
	return (0);
}






