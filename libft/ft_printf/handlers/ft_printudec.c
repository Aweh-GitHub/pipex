/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printudec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:15:44 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/09 23:26:21 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdarg.h>

size_t	ft_printudec(va_list *args)
{
	unsigned int	udec;

	udec = va_arg(*args, unsigned int);
	return (ft_putbase_unsigned(udec, "0123456789"));
}
