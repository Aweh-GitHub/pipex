/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:32:31 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/13 15:55:26 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stddef.h>

int	ft_contains_at(char *str, char *cmp, size_t at_index)
{
	size_t	str_len;
	size_t	cmp_i;

	cmp_i = 0;
	if (str == NULL || cmp == NULL)
		return (ERROR);
	str_len = ft_strlen(str);
	if (at_index >= str_len)
		return (ERROR);
	while (cmp[cmp_i])
	{
		if (str[at_index + cmp_i] != cmp[cmp_i])
			return (FALSE);
		cmp_i++;
	}
	return (TRUE);
}
