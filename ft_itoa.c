/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:38:43 by abarbour          #+#    #+#             */
/*   Updated: 2022/01/27 18:54:50 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	size(int n)
{
	if (n / 10)
		return (1 + size(n / 10));
	return (1);
}

static void	convert(char *str, int n, int i)
{
	if (n / 10)
		convert(str, n / 10, i - 1);
	str[i] = n % 10 + 48;
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	while (*(s1 + i) != '\0')
		i++;
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (*(s1 + i) != '\0')
	{
		*(dest + i) = *(s1 + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s = size(n);
	if (n < 0)
		s++;
	str = (char *)malloc(s + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		convert(str, -n, s - 1);
	}
	else
		convert(str, n, s - 1);
	str[s] = '\0';
	return (str);
}
