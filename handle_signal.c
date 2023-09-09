/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:38:59 by arabelo-          #+#    #+#             */
/*   Updated: 2023/09/09 18:34:49 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minitalk.h"

void	handle_signal(int signal, struct __siginfo *siginfo, void *addr)
{
	static int				bits_counter;
	static unsigned char	c;
	static char				*message;
	static int				chars_counter;

	(void)addr;
	if (signal == SIGUSR1)
		c |= (1 << bits_counter);
	if (!chars_counter && !c && !bits_counter)
		message = NULL;
	bits_counter++;
	if (bits_counter > 7)
	{
		bits_counter = 0;
		if (!handle_string(message, &c, &chars_counter))
			return ;
		message = get_string(message, c, chars_counter);
		c = 0;
	}
}
