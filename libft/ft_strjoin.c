/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:37:41 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/10 15:00:46 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char		*result;
	size_t		str1_len;
	size_t		str2_len;
	size_t		i;

	if (!str1 || !str2)
		return (NULL);
	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	result = malloc(sizeof(char) * (str1_len + str2_len + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < str1_len)
		result[i] = str1[i];
	i = -1;
	while (++i < str2_len)
		result[str1_len + i] = str2[i];
	result[str1_len + str2_len] = '\0';
	return (result);
}
