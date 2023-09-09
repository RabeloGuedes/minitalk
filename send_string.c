/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:24:45 by arabelo-          #+#    #+#             */
/*   Updated: 2023/09/07 21:25:10 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minitalk.h"

void	send_string(pid_t server_pid, char *str)
{
	while (*str)
		send_signal(server_pid, *str++);
	send_signal(server_pid, '\0');
}
