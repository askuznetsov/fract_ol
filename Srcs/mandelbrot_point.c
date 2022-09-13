/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 17:22:33 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/19 15:57:39 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int	count_iterations(double cx, double cy, int iterations)
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
		zy = (2 * zx * zy) + cy;
		zx = temp_x;
		count++;
	}
	return (count);
}
