/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:12:41 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/10 14:52:24 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mem;
	unsigned char	u_value;
	size_t			i;

	mem = (unsigned char *)s;
	u_value = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (mem[i] == u_value)
			return (&mem[i]);
		i++;
	}
	return (NULL);
}
