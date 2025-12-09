/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraytostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 07:20:12 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/07 18:07:38 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static size_t	array_len(char **array)
{
	size_t	array_i;
	size_t	str_i;
	size_t	len;

	array_i = 0;
	len = 0;
	while (array[array_i])
	{
		str_i = 0;
		while (array[array_i][str_i])
		{
			str_i++;
			len++;
		}
		array_i++;
	}
	return (len);
}

char	*ft_arraytostr(char **array)
{
	char	*result;
	size_t	array_i;
	size_t	result_i;
	size_t	cpy_i;
	size_t	len;

	len = array_len(array);
	result = malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	array_i = 0;
	result_i = 0;
	while (array[array_i])
	{
		cpy_i = 0;
		while (array[array_i][cpy_i])
		{
			result[result_i + cpy_i] = array[array_i][cpy_i];
			cpy_i++;
		}
		result_i += cpy_i;
		array_i++;
	}
	return (result);
}
