/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:26:37 by arabelo-          #+#    #+#             */
/*   Updated: 2023/08/30 08:55:08 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minitalk.h"

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
