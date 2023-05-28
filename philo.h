/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:17:44 by haarab            #+#    #+#             */
/*   Updated: 2023/05/28 14:51:37 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>


typedef struct s_vars
{
	int nbr_philo;
	pthread_mutex_t *fork;
	pthread_mutex_t print;
	long int time_to_start;
	long int time_to_eat;
	long int time_to_sleep;
	long int time_to_dead;
}	t_var;

typedef struct s_var
{
	int id;
	pthread_t philo;
	int	fork_left;
	int fork_right;
	t_var *info;
}	t_vars;

int		ft_atoi(char *str);
















// typedef struct s_vars
// {
// 	int count;
// 	int id;
// 	pthread_t phil;
// }	t_vars;

// typedef struct s_philo
// {
// 	int fock_r;
// 	t_vars	*arg;
// 	int fock_l;
// 	int count;
// 	pthread_mutex_t fork_r;
// 	pthread_mutex_t fork_l;
// }	t_philo;

// typedef struct s_var
// {
// 	int count;
// }	t_var;

int		ft_atoi(char *str);

#endif