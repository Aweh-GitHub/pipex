/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:34:46 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/08 10:54:00 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_first(void **array, void *ref, int (*f)(const void *, const void *))
{
	size_t	i;

	if (array == NULL || f == NULL)
		return (NULL);
	i = 0;
	while (array[i] != NULL)
	{
		if (f(array[i], ref) == 1)
			return (array[i]);
		i++;
	}
	return (NULL);
}