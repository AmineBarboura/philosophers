/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:38:17 by abarbour          #+#    #+#             */
/*   Updated: 2022/01/09 20:00:42 by abarbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if ((c <= '9') && (c >= '0'))
		return (c);
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strisnum(char *str)
{
	int		i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i])
		return (0);
	return (1);
}
