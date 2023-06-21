/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:17:44 by haarab            #+#    #+#             */
/*   Updated: 2023/06/21 19:27:15 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_vars
{
	int				nbr_philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	long int		time_to_start;
	long int		time_to_eat;
	long int		time_to_sleep;
	long int		time_to_dead;
	long int		number_meal;
}					t_var;

typedef struct s_var
{
	int				id;
	long int		time_last_eat;
	int				fork_left;
	int				fork_right;
	int				is_dead;
	int				amount_of_food;
	pthread_t		philo;
	t_var			*info;
}					t_vars;

void				all_philoaredead(t_vars *philo);

void				philo_dead(t_vars *philo, int i);

int					ft_deadphilo(t_vars *philo);

void				ft_print(t_vars *philo, char *str);

long int			ft_time(void);

void				sleeeeep(long ti);

long				ft_atoi(char *str);

void				check_arg(t_vars *philo, int ac, char **av);

int					invalid(char *av);

int					check_arguments(char **av);

int					max_min(char **str);

void				time_last_eat(t_vars *philo);

void				check_rotine(t_vars *philo);

void				*routine(void *args);

void				init_thread(t_var *info);

void				init_struct(t_var *info, t_vars *philo, int ac, char **av);

void				destroy_mutex(t_vars *philo);

void				join_threads(t_vars *philo);

#endif