/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:17:44 by haarab            #+#    #+#             */
/*   Updated: 2023/06/18 17:37:57 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>



typedef struct s_vars
{
	int nbr_philo;
	int		met;
	pthread_mutex_t *fork;
	pthread_mutex_t print;
	long int time_to_start;
	long int time_to_eat;
	long int time_to_sleep;
	long int time_to_dead;
	long int  number_meal;
}	t_var;

typedef struct s_var
{
	int id;
	long int akhir_makla;
	pthread_t philo;
	int	fork_left;
	int fork_right;
	int is_dead;
	int amount_of_food;
	int ac;
	t_var *info;
}	t_vars;

int		ft_atoi(char *str);

long int	ft_time(void);

void	sleeeeep(long ti);

int		ft_deadphilo(t_vars *philo);

void ft_print(t_vars *philo, char *str);

void	*routine(void *args);

#endif