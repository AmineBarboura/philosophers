/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:57:52 by abarbour          #+#    #+#             */
/*   Updated: 2022/01/27 23:15:10 by abarbour         ###   ########.fr       */
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

void	print_timestamp_ms(t_philo_table *table)
{
	long int	now;
	char		*str;

	now = get_timestamp();
	str = ft_itoa((int)((now - table->exec_time) / 1000));
	write(1, str, ft_strlen(str));
	write(1, "ms\n", 3);
	free(str);
}

int	free_forks(t_philo **philos, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(philos[i]->right_fork);
		i++;
	}
	return (1);
}

int	free_philos_table(t_philo_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nb && table->philosophers[i])
	{
		free(table->philosophers[i]);
		i++;
	}
	free(table->philosophers);
	return (1);
}
