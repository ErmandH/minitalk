/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni < eharuni@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:32:09 by eharuni           #+#    #+#             */
/*   Updated: 2022/02/06 15:32:09 by eharuni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

void	ft_putstr(char *str);
int		ft_atoi(char *str);
void	send_message(int pid, char *msg);
void	send_signal(int pid, char ascii);
void	error(char *msg);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar(char c);
int		ft_strlen(char *str);
#endif