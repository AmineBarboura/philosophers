/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:39:41 by abarbour          #+#    #+#             */
/*   Updated: 2022/01/27 23:15:52 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

struct		s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	long int		last_time_eating;
};
typedef struct s_philo			t_philo;

struct		s_philo_table
{
	t_philo		**philosophers;
	int			philo_nb;
	int			time_to_eat;
	int			time_to_die;
	int			time_to_sleep;
	int			nb_max_meals;
	int			limit_set;
	long int	exec_time;
};
typedef struct s_philo_table	t_philo_table;

long int	get_timestamp(void);
int			ft_strisnum(char *str);
size_t		ft_atoi(const char *str);
int			free_philos_table(t_philo_table *table);
int			free_forks(t_philo **table, int index);
char		*ft_itoa(int n);
void		print_timestamp_ms(t_philo_table *table);
int			ft_strlen(const char *s);

#endif
