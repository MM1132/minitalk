/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:49:21 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/23 00:06:24 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_lowercase_hex(unsigned long n)
{
	return (put_nbr_base(n, g_lowercase_hex_base));
}

int	put_uppercase_hex(unsigned long n)
{
	return (put_nbr_base(n, g_uppercase_hex_base));
}
