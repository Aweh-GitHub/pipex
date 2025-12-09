/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:16:13 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/10 14:52:52 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*mem1;
	const unsigned char	*mem2;
	size_t				i;

	if (n == 0)
		return (0);
	mem1 = (const unsigned char *)s1;
	mem2 = (const unsigned char *)s2;
	i = 0;
	while (i < n && mem1[i] == mem2[i])
		i++;
	if (i == n)
		return (0);
	return (mem1[i] - mem2[i]);
}
