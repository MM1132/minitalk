/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:08:13 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/15 14:57:49 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*str;
	unsigned char	char_to_find;

	str = (unsigned char *)s;
	char_to_find = (unsigned char)c;
	index = 0;
	while (index < n)
	{
		if (str[index] == char_to_find)
		{
			return (&(((void *)str)[index]));
		}
		index++;
	}
	return (NULL);
}
