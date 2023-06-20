/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:22:52 by haarab            #+#    #+#             */
/*   Updated: 2023/06/20 00:47:21 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		check_arg(t_vars *philo, int ac,char **av)
{
	t_var	*info ;
	int i;
	
	info = malloc(sizeof(t_var));
	info->nbr_philo = ft_atoi(av[1]);
	info->time_to_dead = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	// if (philo->ac == 6)
	// {
	// 	info->number_meal = ft_atoi(av[5]);
	// 	if (info->number_meal == 0)
	// 	{
	// 		printf ("Errorr\n");
	// 		return ;
	// 	}
	// }
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
		if(ac == 6)
			philo[i].amount_of_food = ft_atoi(av[5])+1;
		else
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

int invalid(char *av)
{
	int i = 0;
	int flag = 0;
	while (av[i])
	{
		if (av[i] == '+' || av[i] == '-')
		{
			if (flag == 1 || i > 0)
				return 1;
			flag = 1;
		}
		else if(!(av[i] >= '0' && av[i] <= '9'))
			return 1;
		i++;
	}
	return 0;
}
int check_arguments(char **av)
{
	int i = 1;
	while (av[i])
	{
		if (invalid(av[i]))
		{
			printf("Error1\n");
			return (1);
		}
		i++;
	}
	return 0;
}

int	max_min(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_atoi(str[i]) == 0)
			return 1;
		i++;
	}
	return 0;
}


int main(int ac, char **av)
{

	if (ac < 5 || ac > 6)
	{
		printf ("Error");
		return (0);
	}
	if (check_arguments(av))
		return (1);
	if (max_min(av))
	{
		printf ("Error\n");
		return (0);
	}
	// if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0 || ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
	// {
	// 	printf ("Error\n");
	// 	return (0);	
	// }
	t_vars *philo = NULL;
	philo = malloc(sizeof(t_vars) * ft_atoi(av[1]));
	if (ac == 6)
		philo->ac = ac;
	check_arg(philo,ac, av);
	return (0);
}






