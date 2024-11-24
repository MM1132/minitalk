/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:59:24 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/23 14:23:03 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft.h"

void	send_something(pid_t pid, size_t c, int l)
{
	int	bit;
	int	index;

	index = 0;
	while (index < l)
	{
		bit = (c >> index) & 1;
		if (bit == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		index++;
	}
}

void	send_msg(pid_t pid, char *msg)
{
	int	index;

	send_something(pid, ft_strlen(msg), 64);
	index = 0;
	while (msg[index] != 0)
		send_something(pid, msg[index++], 8);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (ft_printf("Enter: %s <pid> <msg>\n", argv[0]), 1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_printf("Please enter a PID creater than 0\n"), 1);
	return (send_msg(pid, argv[2]), 0);
}
