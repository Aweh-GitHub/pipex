/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:44:51 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/08 10:53:13 by thantoni         ###   ########.fr       */
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

int	ft_contains(const char *str, const char *ref)
{
	size_t	i;
	size_t	cmp_i;
	size_t	ref_len;

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