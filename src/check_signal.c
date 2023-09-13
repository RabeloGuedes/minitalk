/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:01:08 by arabelo-          #+#    #+#             */
/*   Updated: 2023/09/13 08:08:11 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	check_signal(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message sucessfully received!\n");
	else
		ft_printf("Something went wrong, message unsucessfully received!\n");
}
