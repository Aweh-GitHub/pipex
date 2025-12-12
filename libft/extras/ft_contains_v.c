/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_v.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:44:51 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/12 09:59:00 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static	size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_contains_v(const void *ptr, const void *cmp)
{
	char	*str;
	char	*ref;
	size_t	i;
	size_t	cmp_i;
	size_t	ref_len;

	str = (char *) ptr;
	ref = (char *) cmp;
	if (str == NULL || ref == NULL)
		return (0);
	i = 0;
	ref_len = ft_strlen(ref);
	while (str[i])
	{
		cmp_i = 0;
		while (ref[cmp_i] && ref[cmp_i] == str[i + cmp_i])
			cmp_i++;
		if (cmp_i == ref_len)
			return (1);
		i++;
	}
	return (0);
}
