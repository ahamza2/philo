/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:22:52 by haarab            #+#    #+#             */
/*   Updated: 2023/06/17 23:54:28 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_print(t_vars *philo, char *str)
{
	pthread_mutex_lock(&philo->info->print);
	if (philo->is_dead == 1)
	{
		printf ("%ld %d %s\n", (ft_time() - philo->info->time_to_start), philo->id, str);
	}
	pthread_mutex_unlock(&philo->info->print);
}

void siiiiiii(t_vars *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->info->fork[philo->fork_right]);
		ft_print(philo ,"has taken a fork");
		pthread_mutex_lock(&philo->info->fork[philo->fork_left]);
		ft_print(philo ,"has taken a fork");
		// pthread_mutex_lock(&philo->info->print);
		ft_print(philo ,"is eating");
		// pthread_mutex_unlock(&philo->info->print);
		philo->amount_of_food++;
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
	if (philo->id % 2 != 0)
	{
		sleeeeep(200);
		// printf ("str ==== %ld\n", philo->info->time_to_eat);
		// sleep (1);
		// usleep (100);
		// ft_print(philo ,"is thinking");
	}
	siiiiiii(philo);
	return (NULL);
}

int		check_arg(t_vars *philo, char **av)
{
	t_var	*info ;
	int i;
	
	info = malloc(sizeof(t_var));
	info->nbr_philo = ft_atoi(av[1]);
	info->time_to_dead = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->number_meal = ft_atoi(av[5]);
	info->fork = malloc(sizeof(pthread_mutex_t) * info->nbr_philo);
	i = 0;
	info->time_to_start = ft_time();
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
		philo[i].akhir_makla = t;
		philo[i].amount_of_food = -1;
		philo[i].info = info;
		philo[i].fork_left = (i + 1) % info->nbr_philo;
		philo[i].fork_right = i;
		philo[i].id = i + 1;
		philo[i].is_dead = 1;
		// pthread_create(&philo[i].philo, NULL, &routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < info->nbr_philo)
	{
		pthread_create(&philo[i].philo, NULL, &routine, &philo[i]);
		i++;
	}
	while (1)
	{
		if (ft_deadphilo(philo) == 1)
			return (0);
	}
	// int i;
	i = 0;
	while (i < philo->info->nbr_philo)
	{
		pthread_mutex_destroy(&philo->info->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->info->print);
	i = 0;
	while (i < philo->info->nbr_philo)
	{
		pthread_join(philo[i].philo, NULL);
		i++;
	}
}


int main(int ac, char **av)
{
	if (ac < 5 && ac > 6)
	{
		printf ("Error");
		return (0);
	}
	t_vars *philo = NULL;
	philo = malloc(sizeof(t_vars) * ft_atoi(av[1]));
	check_arg(philo, av);
	return (0);
}






