/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ter_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:16:17 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/09 16:30:59 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ter_p(int con, void *val_true, void *val_false)
{
	if (con)
		return (val_true);
	return (val_false);
}
