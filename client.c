/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:02:49 by arabelo-          #+#    #+#             */
/*   Updated: 2023/09/12 09:13:39 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minitalk.h"

int	main(int ac, char **av)
{
	pid_t	server_pid;

	if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);
		if (!is_pid_valid(av[1]))
		{
			ft_putendl_fd("Error: Invalid server_pid!", 2);
			exit(EXIT_FAILURE);
		}
		send_string(server_pid, av[2]);
	}
	else
	{
		ft_putendl_fd("Error -> Usage: ./client SERVER_PID \"Your message\"", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
