/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:52:56 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/09 23:12:31 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "unistd.h"

size_t	ft_putbase(long long int dec, char const *base)
{
	size_t	len;

	len = 0;
	if (dec < 0)
	{
		dec = -dec;
		write(1, "-", 1);
		len++;
	}
	len += ft_putbase_unsigned((unsigned long long int)dec, base);
	return (len);
}

size_t	ft_putbase_unsigned(unsigned long long int udec, char const *base)
{
	size_t	base_len;
	size_t	len;
	char	c;

	base_len = 0;
	while (base[base_len])
		base_len++;
	len = 0;
	if (udec >= base_len)
		len += ft_putbase_unsigned(udec / base_len, base);
	c = base[udec % base_len];
	write(1, &c, 1);
	return (len + 1);
}
