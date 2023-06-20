/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:22:52 by haarab            #+#    #+#             */
/*   Updated: 2023/06/20 21:51:16 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_arg(t_vars *philo, int ac, char **av)
{
	t_var	*info;

	info = malloc(sizeof(t_var));
	if (!info)
		return ;
	info->nbr_philo = ft_atoi(av[1]);
	info->time_to_dead = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->fork = malloc(sizeof(pthread_mutex_t) * info->nbr_philo);
	if (!info->fork)
		return ;
	info->time_to_start = ft_time();
	init_thread(info);
	init_struct(info, philo, ac, av);
	while (1)
	{
		if (ft_deadphilo(philo) == 1)
			return ;
	}
}

int	invalid(char *av)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (av[i])
	{
		if (av[i] == '+' || av[i] == '-')
		{
			if (flag == 1 || i > 0)
				return (1);
			flag = 1;
		}
		else if (!((av[i] >= '0' && av[i] <= '9') || av[i] == ' '))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_arguments(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (invalid(av[i]))
		{
			printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	max_min(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_atoi(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	*philo;

	if (ac < 5 || ac > 6)
	{
		printf("Error");
		return (0);
	}
	if (check_arguments(av))
		return (0);
	if (max_min(av))
	{
		printf("Error\n");
		return (0);
	}
	philo = NULL;
	philo = malloc(sizeof(t_vars) * ft_atoi(av[1]));
	if (!philo)
		return (0);
	if (ac == 6)
		philo->ac = ac;
	check_arg(philo, ac, av);
	join_threads(philo);
	destroy_mutex(philo);
	return (0);
}
