/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:16:17 by thantoni          #+#    #+#             */
/*   Updated: 2026/01/09 14:33:21 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long unsigned	tlu(int con, long unsigned val_true, long unsigned val_false)
{
	if (con)
		return (val_true);
	return (val_false);
}
