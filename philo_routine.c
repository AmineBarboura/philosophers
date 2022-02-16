/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:16:29 by abarbour          #+#    #+#             */
/*   Updated: 2022/02/17 00:13:56 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (!check_death(philo->table))
	{
		if (philo->state <= 0)
			thinking(philo, philo->state);
		else if (philo->state == 1)
		{
			eating(philo);
			if (philo->number_meals == philo->table->nb_max_meals)
				break ;
		}
		else if (philo->state == 2)
			sleeping(philo);
	}
	if (philo->state == 1)
		put_forks_down(philo);
	pthread_mutex_lock(&philo->table->out);
	philo->table->philos_out++;
	pthread_mutex_unlock(&philo->table->out);
	return (0);
}

void	*death_angel(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (!check_death(philo->table))
	{
		if (done_eating(philo))
			philo->table->philos_done_eating++;
		else if (check_time_to_die(philo))
			break ;
		if (philo->table->philos_done_eating == philo->table->nb_max_meals)
			break ;
	}
	return (0);
}

void	*all_out(void *t)
{
	t_philo_table	*table;
	int				i;

	table = (t_philo_table *)t;
	while (!check_out(table))
	{
		usleep(100);
	}
	i = 0;
	while (i < table->philo_nb)
	{
		pthread_join(table->philosophers[i].death_thread, NULL);
		i++;
	}
	usleep(100);
	return (0);
}

void	create_philos(t_philo_table *table, int odd_even)
{
	int	i;

	i = 0;
	while (i < table->philo_nb)
	{
		if (i % 2 == odd_even)
		{
			table->philosophers[i].last_time_eating = get_timestamp();
			pthread_create(&table->philosophers[i].thread, NULL, &routine,
				&table->philosophers[i]);
			pthread_detach(table->philosophers[i].thread);
		}
		usleep(20);
		i++;
	}
}

void	begin_the_feast(t_philo_table *table)
{
	int			i;
	pthread_t	all_out_thread;

	create_philos(table, 0);
	create_philos(table, 1);
	i = 0;
	while (i < table->philo_nb)
	{
		pthread_create(&table->philosophers[i].death_thread, NULL,
			&death_angel, &table->philosophers[i]);
		i++;
	}
	pthread_create(&all_out_thread, NULL, &all_out, table);
	pthread_join(all_out_thread, NULL);
}
