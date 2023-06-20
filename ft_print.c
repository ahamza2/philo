/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:38:43 by haarab            #+#    #+#             */
/*   Updated: 2023/06/18 22:56:52 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_vars *philo, char *str)
{
	pthread_mutex_lock(&philo->info->print);
	if (philo->is_dead == 1)
	{
		printf("%ld %d %s\n", (ft_time() - philo->info->time_to_start),
			philo->id, str);
	}
	pthread_mutex_unlock(&philo->info->print);
}
