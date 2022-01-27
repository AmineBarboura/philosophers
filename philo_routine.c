/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:16:29 by abarbour          #+#    #+#             */
/*   Updated: 2022/01/27 23:52:46 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*routine(void *p)
{
	t_philo *philo;

	philo = (t_philo *)p;
	
}

void	begin_the_feast(t_philo_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nb)
	{
		table->philosophers[i].last_time_eating = get_timestamp();
		//table->philosophers[i].thread
		i++;
	}
}
