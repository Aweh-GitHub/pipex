/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:06:47 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/09 23:13:10 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

size_t	ft_printstr(va_list *args)
{
	char	*str;
	size_t	str_len;

	str = va_arg(*args, char *);
	if (str == NULL)
		return (write(1, "(null)", 6), 6);
	str_len = 0;
	while (str[str_len])
		str_len++;
	write(1, str, str_len);
	return (str_len);
}
