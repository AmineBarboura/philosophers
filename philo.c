/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:00:05 by abarbour          #+#    #+#             */
/*   Updated: 2022/01/09 20:19:27 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

struct	s_test
{
	char	*s;
	pthread_mutex_t	*mute;
};
typedef struct s_test	test;
void	*philo_routine(void *data)
{
	test *d;

	d = (test*)data;
	write(1,d->s,ft_strlen(d->s));
	write(1,"\n", 1);
	return NULL;
}


int	main(int ac, char **av)
{
	int				i;
	pthread_t		p[3];
	pthread_mutex_t	print_mute;
	test			data[3];

	if (ac != 5 && ac != 6)
		return (1);
	i = 1;
	while (i < ac)
	{
		if (av[i] && !ft_strisnum(av[i]))
			return (1);
		i++;
	}
	pthread_mutex_init(&print_mute, NULL);
	i = 0;
	while (i < 3)
	{
		data[i].s = av[i];
		data[i].mute = &print_mute;
		pthread_create(&p[i], NULL, philo_routine, (void *)(&(data[i])));
		i++;
	}
	i = 0;
	while (i < 3)
	{
		pthread_join(p[i], NULL);
		i++;
	}
	return (0);
}
