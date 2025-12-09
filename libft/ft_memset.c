/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:36:04 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/10 14:45:27 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*mem;
	unsigned char	u_value;
	size_t			i;

	mem = (unsigned char *)s;
	u_value = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		mem[i] = u_value;
		i++;
	}
	return (mem);
}
