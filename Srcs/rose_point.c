/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rose_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 15:55:53 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/19 15:57:39 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int	count_iterations_rose(double cx, double cy, int iterations)
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
		temp_x = (zx * zx) - (zy * zy) - zx + cx;
		zy = (2 * zx * zy) - zy + cy;
		zx = temp_x;
		count++;
	}
	return (count);
}
