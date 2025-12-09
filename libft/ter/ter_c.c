/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ter_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:16:17 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/09 16:30:47 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	ter_c(int con, char val_true, char val_false)
{
	if (con)
		return (val_true);
	return (val_false);
}
