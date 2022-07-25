/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni < eharuni@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:28:27 by eharuni           #+#    #+#             */
/*   Updated: 2022/02/06 15:28:27 by eharuni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_atoi(char *str)
{
	int	res;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}
