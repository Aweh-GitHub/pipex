/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:22:25 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/20 16:23:37 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	lerp(double origin, double target, double progress)
{
	if (progress <= 0)
		return (origin);
	if (progress >= 1)
		return (target);
	return (origin + (target - origin) * progress);
}