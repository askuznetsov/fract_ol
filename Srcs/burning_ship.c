/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:54:37 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/19 14:38:41 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <pthread.h>

void		set_pixel_burn(unsigned char *pixel, int count, int max)
{
	double				intens;
	unsigned char		color;

	if (count > max)
		count = max;
	intens = count / (double)max;
	color = (unsigned char)(255 * intens);
	pixel[0] = 0;
	pixel[1] = 0;
	pixel[2] = 0;
	if (intens < 0.6)
		f1(pixel, intens, color);
	else if (intens < 1)
	{
		f2(pixel, intens, color);
	}
	else
	{
		pixel[0] = 0;
		pixel[1] = 0;
		pixel[2] = 0;
	}
}

void		*burn_slave_body(t_param *param)
{
	int				x;
	int				y;
	double			x_real;
	double			y_real;
	unsigned char	*pixel;

	x = 0;
	while (x < param->width)
	{
		y = param->start_y;
		x_real = param->window->pos_x + (x * param->window->scale_x);
		while (y < param->end_y)
		{
			y_real = param->window->pos_y + (y * param->window->scale_y);
			pixel = (unsigned char*)image_point(param->image, x, y);
			set_pixel_burn(pixel, count_iterations_burn(x_real, y_real,
			param->window->detail), param->window->detail);
			y++;
		}
		x++;
	}
	return (NULL);
}

void		*burn_slave(void *param)
{
	return (burn_slave_body(param));
}

static void	init(t_param param[4], t_window *window, t_image *image)
{
	int i;

	i = 0;
	while (i < 4)
	{
		param[i].window = window;
		param[i].image = image;
		param[i].start_y = (i * 150);
		param[i].end_y = (i + 1) * 150;
		param[i].width = WDTH;
		i++;
	}
}

void		burning_ship(t_image *image, t_window *window)
{
	pthread_t	threads[4];
	t_param		param[4];
	int			i;

	i = 0;
	init(param, window, image);
	while (i < 4)
	{
		pthread_create(threads + i, NULL, &burn_slave, param + i);
		i++;
	}
	i = 0;
	while (i < 4)
		pthread_join(threads[i++], NULL);
}
