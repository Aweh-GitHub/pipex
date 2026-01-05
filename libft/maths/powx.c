/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:26:34 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/20 13:37:20 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	powx(double value, int x)
{
	double	result;

	result = 1.0;
	if (x > 0)
		while (x-- > 0)
			result *= value;
	else if (x < 0)
		while (x++ < 0)
			result /= value;
	return (result);
}


double	pow2(double value)
{
	return (powx(value, 2));
}

double	pow3(double value)
{
	return (powx(value, 3));
}