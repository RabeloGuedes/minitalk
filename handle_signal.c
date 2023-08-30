/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:38:59 by arabelo-          #+#    #+#             */
/*   Updated: 2023/08/22 22:04:29 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minitalk.h"

void	handle_signal(int signal)
{
	static int					counter;
	static unsigned char		c;

	if (signal == SIGUSR1)
		c |= (1 << counter);
	else if (signal == SIGUSR2)
		c |= (0 << counter);
	counter++;
	if (counter > 7)
		ft_printf("%c", c);
}