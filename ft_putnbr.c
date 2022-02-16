/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:46:50 by abarbour          #+#    #+#             */
/*   Updated: 2022/02/15 23:53:28 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_put_digit(long int i)
{
	if (i < 0)
		i = -i;
	i = i + 48;
	write(1, &i, 1);
}

static void	ft_putnbr_rec(long int nb)
{
	if (nb / 10 != 0)
		ft_putnbr_rec(nb / 10);
	ft_put_digit(nb % 10);
}

void	ft_putnbr(long int n)
{
	if (n < 0)
		write(1, "-", 1);
	ft_putnbr_rec(n);
}
