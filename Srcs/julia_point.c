/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:42:54 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/17 17:43:18 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	count_iterations_julia(t_window *window, double x, double y, int iterations)
{
	int		count;
	double	temp_x;
	double	zx;
	double	zy;

	zx = x;
	zy = y;
	count = 0;
	while (count < iterations && ((zx * zx) + (zy * zy)) < 4)
	{
		temp_x = (zx * zx) - (zy * zy) + window->cx;
		zy = (2 * zx * zy) + window->cy;
		zx = temp_x;
		count++;
	}
	return (count);
}
