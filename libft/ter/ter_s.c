/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ter_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:16:17 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/09 16:31:01 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ter_s(int con, char *val_true, char *val_false)
{
	if (con)
		return (val_true);
	return (val_false);
}
