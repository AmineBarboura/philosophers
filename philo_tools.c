/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:57:52 by abarbour          #+#    #+#             */
/*   Updated: 2022/02/17 08:48:17 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_timestamp(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL) == 0)
		return (t.tv_sec * 1000 * 1000 + t.tv_usec);
	return (-1);
}

long int	timestamp_ms(t_philo_table *table)
{
	long int	now;

	now = get_timestamp();
	return ((now - table->exec_time) / 1000);
}

int	free_forks(t_philo *philos, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(philos[i].left_fork);
		i++;
	}
	return (1);
}

void	print_action(t_philo_table *table, int id, char *action)
{
	pthread_mutex_lock(&table->print_mutex);
	if (table->someone_died == 0)
	{
		ft_putnbr(timestamp_ms(table));
		write(1, " ms\t", 4);
		ft_putnbr(id);
		write(1, " ", 1);
		write(1, action, ft_strlen(action));
		write(1, "\n", 1);
	}
	pthread_mutex_unlock(&table->print_mutex);
}

void	destroy_all_mutex(t_philo_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nb)
	{
		pthread_mutex_destroy(table->philosophers[i].left_fork);
		pthread_mutex_destroy(&table->philosophers[i].eating);
		pthread_mutex_destroy(&table->philosophers[i].count_meals);
		i++;
	}
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->order);
	pthread_mutex_destroy(&table->done_eating);
	pthread_mutex_destroy(&table->out);
	pthread_mutex_destroy(&table->death);
}
