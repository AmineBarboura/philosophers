/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:39:41 by abarbour          #+#    #+#             */
/*   Updated: 2022/02/17 08:52:18 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

struct		s_philo
{
	pthread_t				thread;
	pthread_t				death_thread;
	int						num;
	int						number_meals;
	int						state;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			eating;
	pthread_mutex_t			count_meals;
	struct s_philo_table	*table;
	long int				last_time_eating;
};
typedef struct s_philo			t_philo;

struct		s_philo_table
{
	t_philo			*philosophers;
	int				philo_nb;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				nb_max_meals;
	int				philos_done_eating;
	int				philos_out;
	int				someone_died;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	order;
	pthread_mutex_t	death;
	pthread_mutex_t	out;
	pthread_mutex_t	done_eating;
	long int		exec_time;
};
typedef struct s_philo_table	t_philo_table;

long int	get_timestamp(void);
int			ft_strisnum(char *str);
size_t		ft_atoi(const char *str);
int			free_forks(t_philo *philos, int index);
long int	timestamp_ms(t_philo_table *table);
int			ft_strlen(const char *s);
void		begin_the_feast(t_philo_table *table);
void		print_action(t_philo_table *table, int id, char *action);
void		pickup_fork(t_philo *philo);
void		announce_death(t_philo *philo);
void		thinking(t_philo *philo, int beginnig);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		put_forks_down(t_philo *philo);
void		ft_putnbr(long int n);
void		destroy_all_mutex(t_philo_table *table);
int			done_eating(t_philo *p);
int			check_death(t_philo_table *table);
int			check_out(t_philo_table *table);
int			check_time_to_die(t_philo *philo);
int			check_done_eating(t_philo_table *table);

#endif
