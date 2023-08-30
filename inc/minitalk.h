/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 22:24:19 by arabelo-          #+#    #+#             */
/*   Updated: 2023/08/30 09:30:09 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "../libft/inc/libft.h"
# include <signal.h>


int		sigaction(int signum, const struct sigaction *sa, struct sigaction *addr)
{
	return (-1);
}
void	send_signal(pid_t server_pid, unsigned char c);
void	handle_signal(int signal);

#endif