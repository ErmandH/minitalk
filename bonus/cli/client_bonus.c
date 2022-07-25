/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:21:56 by eharuni           #+#    #+#             */
/*   Updated: 2022/02/06 15:25:50 by eharuni          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

char	*convert_to_binary(char c)
{
	char	*arr;
	int		i;

	arr = (char *)malloc(9);
	if (!arr)
		return (NULL);
	i = 8;
	arr[i--] = '\0';
	while (i >= 0)
	{
		if (c % 2 == 1)
			arr[i] = '1';
		else
			arr[i] = '0';
		c /= 2;
		i--;
	}
	return (arr);
}

void	send_signal(int pid, char ascii)
{
	int	pow;

	pow = 7;
	while (pow >= 0)
	{
		if (ascii & (1 << pow))
		{
			if (kill(pid, SIGUSR1) == -1)
				error("\033[1m\033[31mError sending signals\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error("\033[1m\033[31mError sending signals\n");
		}
		usleep(100);
		pow--;
	}
}

void	send_message(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_signal(pid, msg[i]);
		i++;
	}
	send_signal(pid, msg[i]);
}

void	handler(int sig)
{
	(void)sig;
	ft_putstr("\033[1m\033[32mMessage Received\n");
	exit(0);
}

int	main(int ac, char **av)
{
	struct sigaction	act;

	if (ac != 3)
	{
		ft_putstr("Usage: ./client <pid> <message>\n");
		return (0);
	}
	act.sa_handler = &handler;
	act.sa_flags = 0;
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		error("Error setting signal handler\n");
	send_message(ft_atoi(av[1]), av[2]);
	while (1)
		pause();
	return (0);
}
