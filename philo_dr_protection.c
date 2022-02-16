/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dr_protection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:29:05 by abarbour          #+#    #+#             */
/*   Updated: 2022/02/17 00:09:00 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	done_eating(t_philo *p)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&p->count_meals);
	if (p->number_meals == p->table->nb_max_meals)
		ret = 1;
	pthread_mutex_unlock(&p->count_meals);
	return (ret);
}

int	check_death(t_philo_table *table)
{
	int	ret;

	ret = 0;
	usleep(100);
	pthread_mutex_lock(&table->death);
	if (table->someone_died)
		ret = 1;
	pthread_mutex_unlock(&table->death);
	return (ret);
}

int	check_out(t_philo_table *table)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&table->out);
	if (table->philos_out >= table->philo_nb)
		ret = 1;
	pthread_mutex_unlock(&table->out);
	return (ret);
}

int	check_time_to_die(t_philo *philo)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&philo->eating);
	if (get_timestamp() - philo->last_time_eating
		>= philo->table->time_to_die * 1000)
	{
		announce_death(philo);
		ret = 1;
	}
	pthread_mutex_unlock(&philo->eating);
	return (ret);
}
