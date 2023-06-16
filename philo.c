/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:22:52 by haarab            #+#    #+#             */
/*   Updated: 2023/06/16 23:15:39 by haarab           ###   ########.fr       */
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
		ft_print(philo ,"is thinking");
		pthread_mutex_lock(&philo->info->fork[philo->fork_right]);
		ft_print(philo ,"has taken a fork");
		pthread_mutex_lock(&philo->info->fork[philo->fork_left]);
		ft_print(philo ,"has taken a fork");
		ft_print(philo ,"is eating");
		pthread_mutex_lock(&philo->info->print);
		philo->akhir_makla = ft_time();
		pthread_mutex_unlock(&philo->info->print);
		pthread_mutex_unlock(&philo->info->fork[philo->fork_right]);
		sleeeeep (philo->info->time_to_eat, philo);
		pthread_mutex_unlock(&philo->info->fork[philo->fork_left]);
		ft_print(philo ,"is sleeping");
		sleeeeep(philo->info->time_to_sleep, philo);
	}
}

void	*routine(void *args)
{
	t_vars *philo;
	philo = (t_vars *)args;
	if (philo->id % 2 != 0)
	{
		// ft_print(philo ,"is thinking");
		sleeeeep(philo->info->time_to_eat, philo);
	}
	siiiiiii(philo);
	return (NULL);
}

int		check_arg(t_vars *philo, char **av)
{
	t_var	*info ;
	int i;
	// int makla;
	
	info = malloc(sizeof(t_var));
	info->nbr_philo = ft_atoi(av[1]);
	info->time_to_dead = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	// makla = ft_atoi(av[5]);
	info->fork = malloc(sizeof(pthread_mutex_t) * info->nbr_philo);
	i = 0;
	info->time_to_start = ft_time();
	while (i < info->nbr_philo)
	{
		pthread_mutex_init(&info->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&info->print, NULL);

	i = 0;
	long  t = ft_time();
	while (i < info->nbr_philo)
	{
		philo[i].info = info;
		philo[i].akhir_makla = t;
		philo[i].fork_left = (i + 1) % info->nbr_philo;
		philo[i].fork_right = i;
		philo[i].id = i + 1;
		philo[i].is_dead = 1;
		// philo[i].amount_of_food = makla;
		pthread_create(&philo[i].philo, NULL, &routine, &philo[i]);
		i++;
	}
	while (1)
	{
		if (ft_deadphilo(philo) == 1)
			return (0);
	}
	i = 0;
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
	return (1);
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







































// int main(int ac, char **av)
// {
// 	t_vars *philo;
// 	t_var counter;
// 	int i;
// 	(void)ac;
// 	counter.count = ft_atoi(av[1]);
// 	// printf("you ++++++++++ %d +++++++++++++++++\n", counter.count);
// 	// printf("hello ===== %d\n", philo.count);
// 	i = 0;
// 	pthread_mutex_init(&mutex, NULL);
// 	philo = malloc(sizeof(t_vars) * counter.count);
// 	while (i < counter.count)
// 	{
// 		philo[i].id = i + 1;
// 		pthread_create(&philo[i].phil, NULL, &routine, &philo[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < counter.count)
// 	{
// 		pthread_join(philo[i].phil, NULL);
// 		i++;
// 	}
// 	pthread_mutex_destroy(&mutex);
// 	printf("str ===== %d\n", philo->id);
// 	pthread_exit (0);
// }




































































































// void	*routine(void *arg)
// {
// 	int index;
// 	index = *(int*)arg;
// 	printf ("index ====== %d\n", index);
// 	if (pthread_mutex_trylock(&mutex) == 0)
// 	{
// 		sleep (1);
// 		printf ("good Luck\n");
// 		pthread_mutex_unlock(&mutex);
// 	}
// 	else
// 	{
// 		sleep (1);
// 		printf ("don't get luck\n");
// 	}
// 	// if (index == 2)
// 	// {
// 	// 	printf ("eting\n");
// 	// }
// 	// if (index == 1)
// 	// {
// 	// 	printf ("sleeping\n");
// 	// }
// 	// if (index == 3) 
// 	// {
// 	// 	printf ("hhhhh 3\n");
// 	// }
// 		// printf ("hamza\n");
// 	return (NULL);
// }

// int main(int ac, char **av)
// {
// 	int i = 0;
// 	int j = 0;;
// 	j = ft_atoi(av[1]);
// 	pthread_mutex_init(&mutex, NULL);
// 	pthread_t th[j];
// 	if (ac >= 1)
// 	{
// 		while (i < j)
// 		{
// 			pthread_create(&th[j], NULL, &routine, &i);
// 			i++;
// 		}
// 		i = 0;
// 		while (i < j)
// 		{
// 			pthread_join(th[j], NULL);
// 			i++;
// 		}
// 	}
// 	pthread_mutex_destroy(&mutex);
// 	// printf ("str === %d\n", );
// 	return (0);
// }


// void	*roll_dice()
// {
// 	static int value;
// 	int *result;
// 	value = (rand() % 6) + 1;
// 	result = malloc(sizeof(int));
// 	*result = value;
// 	printf ("Thread result : %p\n", result);
// 	return ((void*) result);
// }

// int main(int ac, char **av)
// {
// 	int *res;
// 	(void) av;
// 	if (ac != 1)
// 		return (0);
// 	srand(time(NULL));
// 	pthread_t th;
// 	if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
// 	{
// 		return 1;
// 	}
// 	if (pthread_join(th, (void**) &res) != 0)
// 	{
// 		return (2);
// 	}
// 	// pthread_mutex_destroy(&mutex);
// 	printf ("Main res === %p\n", res);
// 	printf ("str === %d\n", *res);
// 	free (res);
// 	return (0);
// }

// int mails = 0;
// pthread_mutex_t mutex;

// void	*routine()
// {
// 	int i;
	
// 	i = 0;
// 	while (i < 10000000)
// 	{
// 		pthread_mutex_lock(&mutex);
// 		mails++;
// 		pthread_mutex_unlock(&mutex);
// 		// printf ("ptr === %d\n", mails);
// 		i++;
// 	}
// 	return (NULL);
// }

// int main(int ac, char **av)
// {
// 	int i;

// 	(void) av;
// 	if (ac != 1)
// 		return (0);
// 	// pthread_t t1, t2, t3, t4;
// 	pthread_t th[16];
// 	i = 0;
// 	pthread_mutex_init(&mutex, NULL);
// 	while (i < 16)
// 	{
// 		if (pthread_create(th + i, NULL, &routine, NULL) != 0)
// 		{
// 			printf ("failed to create thread");
// 			return 1;
// 		}
// 		printf("thread %d has started\n", i);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 16)
// 	{
// 		if (pthread_join(th[i], NULL) != 0)
// 		{
// 			return (2);
// 		}
// 		printf("thread %d has finished\n", i);
// 		i++;
// 	}
// 	pthread_mutex_destroy(&mutex);
// 	printf ("str === %d\n", mails);
// 	return (0);
// }

// int main(int ac, char **av)
// {
// 	int i;

// 	i = 0;
// 	(void) av;
// 	if (ac != 1)
// 		return (0);
// 	pthread_t t1, t2, t3, t4;
// 	pthread_mutex_init(&mutex, NULL);
// 	pthread_create(&t1, NULL, &routine, NULL);
// 	pthread_create(&t2, NULL, &routine, NULL);
// 	pthread_create(&t3, NULL, &routine, NULL);
// 	pthread_create(&t4, NULL, &routine, NULL);
// 	pthread_join(t1, NULL);
// 	pthread_join(t2, NULL);
// 	pthread_join(t3, NULL);
// 	pthread_join(t4, NULL);
// 	pthread_mutex_destroy(&mutex);
// 	printf ("str === %d\n", mails);
// 	return (0);
// }

// int main(int ac, char **av)
// {
// 	int i;

// 	(void) av;
// 	if (ac != 1)
// 		return (0);
// 	// pthread_t t1, t2, t3, t4;
// 	pthread_t th[4];
// 	i = 0;
// 	pthread_mutex_init(&mutex, NULL);
// 	while (i < 4)
// 	{
// 		if (pthread_create(th + i, NULL, &routine, NULL) != 0)
// 		{
// 			printf ("failed to create thread");
// 			return 1;
// 		}
// 		printf("thread %d has started\n", i);
// 		if (pthread_join(th[i], NULL) != 0)
// 		{
// 			return (2);
// 		}
// 		printf("thread %d has finished\n", i);
// 		i++;
// 	}
// 	pthread_mutex_destroy(&mutex);
// 	printf ("str === %d\n", mails);
// 	return (0);
// }




// int fuel = 0;

// pthread_mutex_t mutex;


// void	*routine(void *args)
// {
// 	int i;
// 	i = 1;
// 	t_philo *philo = (t_philo *)args;
// 	// t_var counter;
// 	pthread_mutex_lock(&mutex);
// 	// // while (1);
// 	// // {
// 	// // 	if (philo->id )
// 	// // }
// 	// // printf("count ++++++++++ %d +++++++++++++++++\n", you.count);
	
// 	// // {
// 	// 	// if (rand() % 2 != 0)	
// 	// 		printf("sleeping ++++++++++ %d +++++++++++++++++\n", philo->arg->id);
// 	// 	// if (rand() % 2 == 0)
// 	// 	// {
// 	// 		printf("eating ++++++++++ %d +++++++++++++++++\n", philo->arg->id);
// 	// 	// }
// 	// 	// else
// 	// 	// {
// 	// 		printf("thinking ++++++++++ %d +++++++++++++++++\n", philo->arg->id);

// 	pthread_mutex_unlock(&mutex);
// 	return (NULL);
// }

// int main(int ac, char **av)
// {
// 	t_vars *philo;
// 	t_var counter;
// 	int i;
// 	(void)ac;
// 	counter.count = ft_atoi(av[1]);
// 	// printf("you ++++++++++ %d +++++++++++++++++\n", counter.count);
// 	// printf("hello ===== %d\n", philo.count);
// 	i = 0;
	
// 	philo = malloc(sizeof(t_vars) * counter.count);
// 	while (i < counter.count)
// 	{
// 		pthread_mutex_init(&mutex, NULL);
// 		philo[i].id = i + 1;
// 		pthread_create(&philo[i].phil, NULL, &routine, &philo[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < counter.count)
// 	{
// 		pthread_join(philo[i].phil, NULL);
// 		i++;
// 	}
// 	pthread_mutex_destroy(&mutex);
// 	printf("str ===== %d\n", philo->id);
// 	pthread_exit (0);
// }








// int fuel = 0;

// pthread_mutex_t mutex;

// void	*routine(void *args)
// {
// 	int i;
// 	i = 1;
// 	t_vars *philo = (t_vars *)args;
// 	pthread_mutex_lock(&mutex);
// 	// printf("count ++++++++++ %d +++++++++++++++++\n", you.count);
// 	while (i < philo->id)
// 	{
// 		if (rand() % 2 != 0)	
// 			printf("sleeping ++++++++++ %d +++++++++++++++++\n", philo->id);
// 		if (rand() % 2 == 0)
// 		{
// 			printf("eating ++++++++++ %d +++++++++++++++++\n", philo->id);
// 			i++;
// 		}
// 		else
// 		{
// 			printf("thinking ++++++++++ %d +++++++++++++++++\n", philo->id);
// 		}
// 		i++;
// 	}
// 	pthread_mutex_unlock(&mutex);
// 	return (NULL);
// }

// int main(int ac, char **av)
// {
// 	t_vars *philo;
// 	t_var counter;
// 	int i;
// 	(void)ac;
// 	counter.count = ft_atoi(av[1]);
// 	// printf("you ++++++++++ %d +++++++++++++++++\n", counter.count);
// 	// printf("hello ===== %d\n", philo.count);
// 	i = 0;
// 	pthread_mutex_init(&mutex, NULL);
// 	philo = malloc(sizeof(t_vars) * counter.count);
// 	while (i < counter.count)
// 	{
// 		philo[i].id = i + 1;
// 		pthread_create(&philo[i].phil, NULL, &routine, &philo[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < counter.count)
// 	{
// 		pthread_join(philo[i].phil, NULL);
// 		i++;
// 	}
// 	pthread_mutex_destroy(&mutex);
// 	printf("str ===== %d\n", philo->id);
// 	pthread_exit (0);
// }