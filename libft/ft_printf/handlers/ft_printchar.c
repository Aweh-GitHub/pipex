/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:05:25 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/09 23:12:47 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

size_t	ft_printchar(va_list *args)
{
	char	c;

	c = (char) va_arg(*args, int);
	write(1, &c, 1);
	return (1);
}
