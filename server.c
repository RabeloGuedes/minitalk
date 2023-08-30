/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 22:35:30 by arabelo-          #+#    #+#             */
/*   Updated: 2023/08/30 08:57:30 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minitalk.h"

void	handle_signal(int signal)
{
	static int					counter;
	static unsigned char		c;

	if (signal == SIGUSR1)
		c |= (1 << counter);
	// else if (signal == SIGUSR2)
	// 	c &= ~(1 << counter);
	counter++;
	if (counter > 7)
	{
		ft_printf("%c", c);
		c = 0;
		counter = 0;
	}
}

int	main(void)
{
	pid_t				process_id;
	struct sigaction	sa;
	int					signal_res;

	process_id = getpid();
	sa.__sigaction_u.__sa_handler = handle_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("%i\n", process_id);
	while (1)
	{
		pause();
	}
	return (0);
}
