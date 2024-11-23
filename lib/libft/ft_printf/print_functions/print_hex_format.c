/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:34:21 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/23 00:06:08 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

const char	g_lowercase_hex_base[] = "0123456789abcdef";
const char	g_uppercase_hex_base[] = "0123456789ABCDEF";

int	print_lowercase_hex_format(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (put_lowercase_hex(n));
}

int	print_uppercase_hex_format(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (put_uppercase_hex(n));
}
