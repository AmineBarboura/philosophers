/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:43:54 by abarbour          #+#    #+#             */
/*   Updated: 2022/01/27 23:09:50 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_atoi(const char *str)
{
	size_t	i;
	size_t	nb;
	int		s;

	nb = 0;
	s = 1;
	i = 0;
	while ((*(str + i) != '\0') && (((*(str + i) < 14) && (*(str + i) > 8))
			|| (*(str + i) == 32)))
		i++;
	if (*(str + i) == 45)
	{
		s = s * -1;
		i++;
	}
	else if (*(str + i) == 43)
		i++;
	while ((*(str + i) != '\0') && (*(str + i) > 47) && (*(str + i) < 58))
	{
		nb = nb * 10 + s * (*(str + i) - 48);
		i++;
	}
	return (nb);
}

int	ft_isdigit(int c)
{
	if ((c <= '9') && (c >= '0'))
		return (c);
	return (0);
}

int	ft_strisnum(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i])
		return (0);
	return (1);
}
