/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:37:43 by abarbour          #+#    #+#             */
/*   Updated: 2022/01/27 23:25:57 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_table(t_philo_table *table, int ac, char **av)
{
	int		i;

	table->exec_time = get_timestamp();
	i = 1;
	while (i < ac)
	{
		if (!ft_strisnum(av[i]))
			return (1);
		i++;
	}
	table->philo_nb = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->limit_set = 0;
	if (ac == 6)
	{
		table->nb_max_meals = ft_atoi(av[5]);
		table->limit_set = 1;
	}
	return (0);
}

int	check_values(t_philo_table *table)
{
	if (table->philo_nb <= 0)
		return (1);
	if (table->time_to_die < 0)
		return (1);
	if (table->time_to_eat < 0)
		return (1);
	if (table->time_to_sleep < 0)
		return (1);
	if (table->limit_set == 1 && table->nb_max_meals < 0)
		return (1);
	return (0);
}

int	init_forks(t_philo_table *table, int i)
{
	table->philosophers[i]->right_fork = malloc(sizeof(pthread_mutex_t));
	if (!(table->philosophers[i]->right_fork))
		return (free_forks(table->philosophers, i));
	if (i > 0)
		table->philosophers[i]->left_fork
			= table->philosophers[i - 1]->right_fork;
	if (i == table->philo_nb - 1)
		table->philosophers[0]->left_fork = table->philosophers[i]->right_fork;
	return (0);
}

int	invite_philos(t_philo_table	*table)
{
	int	i;

	table->philosophers = malloc(sizeof(t_philo *) * (table->philo_nb + 1));
	if (!table->philosophers)
		return (1);
	i = 0;
	while (i < table->philo_nb)
	{
		table->philosophers[i] = NULL;
		i++;
	}
	table->philosophers[i] = NULL;
	i = 0;
	while (i < table->philo_nb)
	{
		table->philosophers[i] = malloc(sizeof(t_philo));
		if (!table->philosophers[i] || init_forks(table, i))
			return (free_philos_table(table));
		i++;
	}
	table->philosophers[i] = NULL;
	return (0);
}

int	main(int ac, char **av)
{
	t_philo_table	table;

	if (ac != 5 && ac != 6)
		return (1);
	if (init_table(&table, ac, av) || check_values(&table))
		return (1);
	if (invite_philos(&table))
		return (1);
	free_forks(table.philosophers, table.philo_nb);
	free_philos_table(&table);
	return (0);
}
