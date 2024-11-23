/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:59:22 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/23 10:12:49 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft.h"

static void	signal_handler(int signum)
{
	static int	bits[8];
	static int	bit_index;
	char		c;

	if (signum == SIGUSR1)
		bits[bit_index] = 0;
	else if (signum == SIGUSR2)
		bits[bit_index] = 1;
	bit_index++;
	if (bit_index == 8)
	{
		c = 0;
		bit_index = 0;
		while (bit_index < 8)
		{
			c |= (bits[bit_index] << bit_index);
			bits[bit_index] = 0;
			bit_index++;
		}
		bit_index = 0;
		ft_printf("%c", c);
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
