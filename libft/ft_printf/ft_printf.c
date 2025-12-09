/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:25:54 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/14 22:01:39 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	is_format(char const c_format)
{
	if (c_format == FORMAT_CHAR)
		return (1);
	if (c_format == FORMAT_STR)
		return (1);
	if (c_format == FORMAT_PTR)
		return (1);
	if (c_format == FORMAT_DEC || c_format == FORMAT_INT)
		return (1);
	if (c_format == FORMAT_UDEC)
		return (1);
	if (c_format == FORMAT_HEX_LOW)
		return (1);
	if (c_format == FORMAT_HEX_UPR)
		return (1);
	if (c_format == FORMAT_PERCENT)
		return (1);
	return (0);
}

static size_t	output_format(char const c_format, va_list *args)
{
	if (c_format == FORMAT_CHAR)
		return (ft_printchar(args));
	if (c_format == FORMAT_STR)
		return (ft_printstr(args));
	if (c_format == FORMAT_PTR)
		return (ft_printptr(args));
	if (c_format == FORMAT_DEC || c_format == FORMAT_INT)
		return (ft_printdec(args));
	if (c_format == FORMAT_UDEC)
		return (ft_printudec(args));
	if (c_format == FORMAT_HEX_LOW)
		return (ft_printhexlow(args));
	if (c_format == FORMAT_HEX_UPR)
		return (ft_printhexupr(args));
	if (c_format == FORMAT_PERCENT)
		return (ft_printpercent());
	return (0);
}

static void	register_output(size_t add_wc, size_t add_i, size_t *wc, size_t *i)
{
	*wc += add_wc;
	*i += add_i;
}

int	ft_printf(char const *f, ...)
{
	va_list	args;
	size_t	i;
	size_t	wc;

	if (f == NULL)
		return (-1);
	va_start(args, f);
	i = 0;
	wc = 0;
	while (f[i])
	{
		if (f[i] != FLAG || (f[i] == FLAG && f[i + 1] && !is_format(f[i + 1])))
			register_output(ft_printdefault(f[i]), 1, &wc, &i);
		else if (f[i + 1] != '\0')
			register_output(output_format(f[i + 1], &args), 2, &wc, &i);
		else
			register_output(0, 1, &wc, &i);
	}
	va_end(args);
	return (wc);
}
