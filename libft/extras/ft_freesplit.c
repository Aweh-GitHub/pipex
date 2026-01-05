/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:32:08 by thantoni          #+#    #+#             */
/*   Updated: 2026/01/03 17:04:58 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

void	ft_freesplit(char **split)
{
	size_t	i;

	if (split == NULL)
		return ;
	i = 0;
	while (split[i])
	{
		ft_free((void **)&(split[i]));
		i++;
	}
	ft_free((void **)&split);
}
