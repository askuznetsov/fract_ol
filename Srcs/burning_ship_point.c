/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:53:48 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/17 18:00:40 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int		count_iterations_burn(double cx, double cy, int iterations)
{
	int		count;
	double	temp_x;
	double	zx;
	double	zy;

	zx = 0;
	zy = 0;
	count = 0;
	while (count < iterations && ((zx * zx) + (zy * zy)) < 4)
	{
		temp_x = (zx * zx) - (zy * zy) + cx;
		zy = 2 * fabs(zx) * fabs(zy) + cy;
		zx = temp_x;
		count++;
	}
	return (count);
}
