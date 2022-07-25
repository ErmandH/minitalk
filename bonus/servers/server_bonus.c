/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni < eharuni@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:29:35 by eharuni           #+#    #+#             */
/*   Updated: 2022/02/06 15:29:35 by eharuni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

void	handler(int sig, siginfo_t *siginfo, void *unused)
{
	static int	bit_move;
	static int	c;
	static int	null_count;

	(void)unused;
	if (sig == SIGUSR1)
	{
		c += 1 << (7 - bit_move);
		null_count = 0;
	}
	else if (sig == SIGUSR2)
		null_count += 1;
	bit_move += 1;
	if (bit_move == 8)
	{		
		ft_putchar(c);
		bit_move = 0;
		c = 0;
		if (null_count >= 8)
		{
			if (kill(siginfo->si_pid, SIGUSR2) == -1)
				error("Error sigaction\n");
		}				
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		error("Error sigaction\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		error("Error sigaction\n");
	ft_putstr("Server PID: ");
	ft_putnbr_fd(getpid(), 1);
	ft_putstr("\n");
	while (1)
		pause();
	return (0);
}
