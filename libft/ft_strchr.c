/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:18:58 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/10 14:50:17 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*u_str;
	unsigned char		u_value;
	size_t				i;

	u_str = (const unsigned char *)s;
	u_value = (unsigned char) c;
	i = 0;
	while (u_str[i])
	{
		if (u_str[i] == u_value)
			return (&((char *)u_str)[i]);
		i++;
	}
	if (u_value == '\0')
		return (&((char *)u_str)[i]);
	return (NULL);
}
