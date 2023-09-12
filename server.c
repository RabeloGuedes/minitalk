/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 22:35:30 by arabelo-          #+#    #+#             */
/*   Updated: 2023/09/12 08:48:55 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minitalk.h"

int	main(void)
{
	pid_t				process_id;
	struct sigaction	sa;
	int					signal_res;

	process_id = getpid();
	sa.sa_handler = handle_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction_config(&sa);
	ft_printf("%i\n", process_id);
	while (1)
		pause();
	return (0);
}
