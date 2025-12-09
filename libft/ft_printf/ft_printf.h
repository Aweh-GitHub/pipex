/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:28:12 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/08 11:07:37 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>

# define FLAG '%'
# define FORMAT_CHAR 'c'
# define FORMAT_STR 's'
# define FORMAT_PTR 'p'
# define FORMAT_DEC 'd'
# define FORMAT_INT 'i'
# define FORMAT_UDEC 'u'
# define FORMAT_HEX_LOW 'x'
# define FORMAT_HEX_UPR 'X'
# define FORMAT_PERCENT '%'

size_t	ft_putbase_unsigned(unsigned long long int udec, char const *base);
size_t	ft_putbase(long long int dec, char const *base);

size_t	ft_printdefault(char c);
size_t	ft_printchar(va_list *args);
size_t	ft_printstr(va_list *args);
size_t	ft_printptr(va_list *args);
size_t	ft_printdec(va_list *args);
size_t	ft_printudec(va_list *args);
size_t	ft_printhexlow(va_list *args);
size_t	ft_printhexupr(va_list *args);
size_t	ft_printpercent(void);

#endif