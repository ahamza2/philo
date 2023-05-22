/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:22:52 by haarab            #+#    #+#             */
/*   Updated: 2023/05/22 21:45:38 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int fuel = 0;

pthread_mutex_t mutex;

void	*rool_rool()
{
	pthread_mutex_lock(&mutex);
	fuel -= 45;
	printf ("fuel == -45 == %d\n", fuel);
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

void	*routine()
{
	int i;
	i = 0;
	while (i < 2)
	{
		pthread_mutex_lock(&mutex);
		fuel += 15;
		printf ("fuel == +15 == %d\n", fuel);
		pthread_mutex_unlock(&mutex);
		i++;
	}
	return (NULL);
}

int main(int ac, char **av)
{
	int i = 0;
	int j = 0;;
	j = ft_atoi(av[1]);
	pthread_mutex_init(&mutex, NULL);
	pthread_t th[j];
	if (ac >= 1)
	{
		while (i < j)
		{
			if (i == 1)
				pthread_create(&th[j], NULL, &rool_rool, NULL);
			else
				pthread_create(&th[j], NULL, &routine, NULL);
			i++;
		}
		i = 0;
		while (i < j)
		{
			pthread_join(th[j], NULL);
			i++;
		}
	}
	pthread_mutex_destroy(&mutex);
	// printf ("str === %d\n", );
	return (0);
}



















































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