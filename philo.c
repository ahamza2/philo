/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:22:52 by haarab            #+#    #+#             */
/*   Updated: 2023/05/21 16:57:52 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int mails = 0;
pthread_mutex_t mutex;

void	*routine()
{
	int i;
	
	i = 0;
	while (i < 10000000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
		// printf ("ptr === %d\n", mails);
		i++;
	}
	return (NULL);
}



int main(int ac, char **av)
{
	int i;

	(void) av;
	if (ac != 1)
		return (0);
	// pthread_t t1, t2, t3, t4;
	pthread_t th[16];
	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 16)
	{
		if (pthread_create(th + i, NULL, &routine, NULL) != 0)
		{
			printf ("failed to create thread");
			return 1;
		}
		printf("thread %d has started\n", i);
		i++;
	}
	i = 0;
	while (i < 16)
	{
		if (pthread_join(th[i], NULL) != 0)
		{
			return (2);
		}
		printf("thread %d has finished\n", i);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	printf ("str === %d\n", mails);
	return (0);
}

























































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