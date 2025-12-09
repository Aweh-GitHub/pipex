/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:04:51 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/11 15:59:54 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	copy_backward(unsigned char *dest, const \
	unsigned char *src, size_t n)
{
	while (n > 0)
	{
		n--;
		dest[n] = src[n];
	}
}

static void	copy_forward(unsigned char *dest, const \
	unsigned char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cast_dest;
	unsigned char	*cast_src;

	if (!dest && !src)
		return (NULL);
	cast_dest = (unsigned char *)dest;
	cast_src = (unsigned char *)src;
	if (cast_dest > cast_src)
		copy_backward(cast_dest, cast_src, n);
	else
		copy_forward(cast_dest, cast_src, n);
	return (dest);
}
