/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:37:31 by abarbour          #+#    #+#             */
/*   Updated: 2022/02/16 20:38:11 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_forks_down(t_philo *philo)
{
	if (philo->right_fork)
		pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	thinking(t_philo *philo, int beginning)
{
	if (beginning != -1)
		print_action(philo->table, philo->num, "is thinking");
	if (beginning == -1)
		pthread_mutex_lock(&philo->table->order);
	pickup_fork(philo);
	if (beginning == -1)
		pthread_mutex_unlock(&philo->table->order);
	philo->state = 1;
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->eating);
	print_action(philo->table, philo->num, "is eating");
	philo->last_time_eating = get_timestamp();
	pthread_mutex_unlock(&philo->eating);
	usleep(philo->table->time_to_eat * 1000);
	put_forks_down(philo);
	philo->state = 2;
	pthread_mutex_lock(&philo->count_meals);
	philo->number_meals++;
	pthread_mutex_unlock(&philo->count_meals);
}

void	sleeping(t_philo *philo)
{
	print_action(philo->table, philo->num, "is sleeping");
	usleep(philo->table->time_to_sleep * 1000);
	philo->state = 0;
}

void	pickup_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo->table, philo->num, "has taken a fork");
	if (!philo->right_fork)
		usleep(philo->table->time_to_die * 1000 + 2000);
	else
		pthread_mutex_lock(philo->right_fork);
	print_action(philo->table, philo->num, "has taken a fork");
}
