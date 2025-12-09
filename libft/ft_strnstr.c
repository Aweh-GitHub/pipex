/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:45:42 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/10 14:53:46 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	find_i;

	if (needle[0] == '\0')
		return ((char *)haystack);
	if (!haystack && n == 0)
		return (NULL);
	i = 0;
	while (haystack[i] && i < n)
	{
		find_i = 0;
		while (needle[find_i]
			&& haystack[i + find_i]
			&& needle[find_i] == haystack[i + find_i]
			&& i + find_i < n)
			find_i++;
		if (!needle[find_i])
			return (&((char *)haystack)[i]);
		i++;
	}
	return (NULL);
}
