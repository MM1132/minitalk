/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:59:22 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/24 12:00:16 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft.h"

static size_t	receive(int *bit_index, int bits[64], int l)
{
	size_t	length;

	if (*bit_index == l)
	{
		length = 0;
		*bit_index = 0;
		while (*bit_index < l)
		{
			length |= (bits[*bit_index] << *bit_index);
			bits[*bit_index] = 0;
			(*bit_index)++;
		}
		*bit_index = 0;
		return (length);
	}
	return (0);
}

static void	set_bit(int signum, int *bit_index, int bits[64])
{
	if (signum == SIGUSR1)
		bits[*bit_index] = 0;
	else if (signum == SIGUSR2)
		bits[*bit_index] = 1;
	(*bit_index)++;
}

static void	print_thing(char **string, size_t *i)
{
	*i = 0;
	ft_printf("%s\n", *string);
	*string = NULL;
	free(*string);
}

static void	signal_handler(int signum)
{
	static int		bits[64];
	static int		bit_index;
	static size_t	string_length;
	static size_t	i;
	static char		*string;

	set_bit(signum, &bit_index, bits);
	if (string == NULL)
	{
		string_length = receive(&bit_index, bits, 64);
		if (string_length == 0)
			return ;
		string = malloc(sizeof(char) * (string_length + 1));
		string[string_length] = 0;
		if (string == NULL)
			return ;
		i = 0;
		return ;
	}
	string[i] = (char) receive(&bit_index, bits, 8);
	if (string[i] != 0)
		i++;
	if (i >= string_length)
		print_thing(&string, &i);
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
