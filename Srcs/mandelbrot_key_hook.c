/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_key_hook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 12:51:47 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/16 16:25:08 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define SPD 1.15

#include <math.h>
#include <stdio.h>

int	scale_img(t_window *window, double scale, int x, int y)
{
	double old_val;
	double new_val;

	if (window == NULL || (window->detail < 15 && scale > 1))
		return (1);
	old_val = window->pos_x + x * window->scale_x;
	new_val = window->pos_x + x * window->scale_x * scale;
	window->pos_x -= (new_val - old_val);
	old_val = window->pos_y + y * window->scale_y;
	new_val = window->pos_y + y * window->scale_y * scale;
	window->pos_y -= (new_val - old_val);
	if (scale > 1)
		window->detail -= 1;
	else
		window->detail += 1;
	window->scale_x *= scale;
	window->scale_y *= scale;
	return (0);
}

int	mouse_hook(int key, int x, int y, void *par)
{
	t_key_hook_param *param;

	param = par;
	if (key == 5)
		scale_img(param->window, 1 / SPD, x, y);
	if (key == 4)
		scale_img(param->window, SPD, x, y);
	if (key == 4 || key == 5)
	{
		ft_memset(param->image->img_data, 0, param->image->sz_ln * HGHT);
		(*param->f)(param->image, param->window);
		mlx_put_image_to_window(param->mlx->mlx_ptr,
		param->mlx->win_ptr, param->image->img_ptr, 0, 0);
		return (0);
	}
	return (0);
}
