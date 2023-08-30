/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:02:49 by arabelo-          #+#    #+#             */
/*   Updated: 2023/08/30 09:59:04 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minitalk.h"

void	send_string(pid_t server_pid, char *str)
{
	while (*str)
		send_signal(server_pid, *str++);
}

void	send_signal(pid_t server_pid, unsigned char c)
{
	unsigned int	i;

	i = 1;
	while (i <= 128)
	{
		if ((c & i) == 0)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		i *= 2;
		usleep(50);
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);
		send_string(server_pid, av[2]);
		while (1)
		{
			pause();
		}
	}
	else
	{
		ft_printf("Error -> Usage: ./client SERVER_PID \"Your message\"");
		return (1);
	}
	return (0);
}
