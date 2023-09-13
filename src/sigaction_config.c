/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigaction_config.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:06:29 by arabelo-          #+#    #+#             */
/*   Updated: 2023/09/13 08:08:11 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	sigaction_config(struct	sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) == -1)
	{
		ft_putendl_fd("Error: sigaction by setting SIGUSR1", 2);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, sa, NULL) == -1)
	{
		ft_putendl_fd("Error: sigaction by setting SIGUSR2", 2);
		exit(EXIT_FAILURE);
	}
}
