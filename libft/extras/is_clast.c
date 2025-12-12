/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_clast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:49:53 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/12 09:59:26 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	is_clast(char *str, char cmp)
{
	size_t	i;

	if (str == NULL)
		return ('\0');
	i = 0;
	while (str[i + 1])
		i++;
	return (str[i] == cmp);
}
