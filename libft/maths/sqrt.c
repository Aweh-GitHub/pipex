/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:32:24 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/20 13:33:30 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	sqrt(double value)
{
	double	result;
	double	tmp;

	if (value < 0)
		return (0);
	if (value == 0 || value == 1)
		return (value);
	result = value / 2;
	tmp = 0;
	while (result != tmp)
	{
		tmp = result;
		result = ((value / tmp) + tmp) / 2;
	}
	return (result);
}