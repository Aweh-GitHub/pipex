/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:48:01 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/10 14:28:11 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nelem, size_t elsize)
{
	unsigned char	*mem;
	size_t			alloc_size;
	size_t			i;

	alloc_size = nelem * elsize;
	mem = malloc(alloc_size);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < alloc_size)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
