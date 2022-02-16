/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:37:43 by abarbour          #+#    #+#             */
/*   Updated: 2022/02/16 23:57:49 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_table(t_philo_table *table, int ac, char **av)
{
	int		i;

	table->exec_time = get_timestamp();
	i = 0;
	while (++i < ac)
		if (!ft_strisnum(av[i]))
			return (1);
	table->philo_nb = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->philos_done_eating = 0;
	table->philos_out = 0;
	table->someone_died = 0;
	table->nb_max_meals = -1;
	if (ac == 6)
		table->nb_max_meals = ft_atoi(av[5]);
	if (pthread_mutex_init(&table->print_mutex, NULL)
		|| pthread_mutex_init(&table->order, NULL)
		|| pthread_mutex_init(&table->out, NULL)
		|| pthread_mutex_init(&table->death, NULL))
		return (1);
	return (0);
}

int	check_values(t_philo_table *table)
{
	if (table->philo_nb <= 0)
		return (1);
	if (table->time_to_die <= 0)
		return (1);
	if (table->time_to_eat <= 0)
		return (1);
	if (table->time_to_sleep <= 0)
		return (1);
	if (table->nb_max_meals < -1)
		return (1);
	return (0);
}

int	init_forks(t_philo_table *table, int i)
{
	int	j;

	table->philosophers[i].left_fork = malloc(sizeof(pthread_mutex_t));
	table->philosophers[i].right_fork = NULL;
	if (!(table->philosophers[i].left_fork))
		return (free_forks(table->philosophers, i));
	if (pthread_mutex_init(table->philosophers[i].left_fork, NULL))
	{
		free_forks(table->philosophers, i);
		free(table->philosophers[i].left_fork);
		return (1);
	}
	if (i == table->philo_nb - 1 && i != 0)
	{
		j = 0;
		while (j < table->philo_nb)
		{
			table->philosophers[j].right_fork
				= table->philosophers[(j + 1) % table->philo_nb].left_fork;
			j++;
		}
	}
	return (0);
}

int	invite_philos(t_philo_table	*table)
{
	int	i;

	table->philosophers = malloc(sizeof(t_philo) * (table->philo_nb));
	if (!table->philosophers)
		return (1);
	i = 0;
	while (i < table->philo_nb)
	{
		if (pthread_mutex_init(&table->philosophers[i].eating, NULL)
			|| pthread_mutex_init(&table->philosophers[i].count_meals, NULL)
			|| init_forks(table, i))
		{
			free(table->philosophers);
			return (1);
		}
		table->philosophers[i].num = i + 1;
		table->philosophers[i].state = -1;
		table->philosophers[i].number_meals = 0;
		table->philosophers[i].table = table;
		i++;
	}
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
	begin_the_feast(&table);
	destroy_all_mutex(&table);
	free_forks(table.philosophers, table.philo_nb);
	free(table.philosophers);
	return (0);
}
