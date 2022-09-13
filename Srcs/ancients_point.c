/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ancients_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 15:36:46 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/19 15:42:12 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int	count_iterations_anc(double cx, double cy, int iterations)
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
		temp_x = (zx * zx * zx) - (zy * zy) + cx;
		zy = (2 * zx * zy * zy) + cy;
		zx = temp_x;
		count++;
	}
	return (count);
}
