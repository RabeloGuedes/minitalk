/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pid_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 08:54:35 by arabelo-          #+#    #+#             */
/*   Updated: 2023/09/13 08:04:31 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minitalk.h"

int	is_pid_valid(char *pid_str)
{
	size_t	pid_str_len;
	unsigned long long	pid;

	pid_str_len = ft_strlen(pid_str);
	pid = ft_atoll(pid_str);
	if (pid <= 0 || pid_str_len > 10 || pid > INT32_MAX)
		return (0);
	return (1);
}
