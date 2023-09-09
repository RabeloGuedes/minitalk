/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 22:24:19 by arabelo-          #+#    #+#             */
/*   Updated: 2023/09/09 18:38:04 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# ifndef WAIT_TIME
#  define WAIT_TIME 500
# endif

# include "../libft/inc/libft.h"
# include <signal.h>

void	send_signal(pid_t server_pid, unsigned char c);
void	send_string(pid_t server_pid, char *str);
void	handle_signal(int signal, struct __siginfo *siginfo, void *addr);
void	handle_signal_bonus(int signal, struct __siginfo *siginfo, void *addr);
void	check_signal(int signal);
void	sigaction_config(struct	sigaction *sa);
char	*get_string(char *old_message, unsigned char c, int chars_counter);
int		handle_string(char *message, unsigned char *c, int *chars_counter);

#endif
