/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_key_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 19:17:57 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/17 19:17:57 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	init_interval_x(int x)
{
	double	percent;

	if (x > 800)
		x = 800;
	percent = (double)x / WDTH;
	return (-1 + 2 * percent);
}

double	init_interval_y(int y)
{
	double	percent;

	if (y > 600)
		y = 600;
	percent = (double)y / HGHT;
	return (-1 + 2 * percent);
}

int		mouse_move(int x, int y, void *par)
{
	t_key_hook_param	*param;

	param = par;
	(param)->window->cx = init_interval_x(x);
	(param)->window->cy = init_interval_y(y);
	(*((param)->f))((param)->image, (param)->window);
	mlx_put_image_to_window(param->mlx->mlx_ptr,
	param->mlx->win_ptr, param->image->img_ptr, 0, 0);
	return (0);
}
