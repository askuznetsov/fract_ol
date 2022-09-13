/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:53:02 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/19 15:16:41 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_window *window)
{
	window->pos_x = -2;
	window->pos_y = -2;
	window->scale_x = (double)4 / WDTH;
	window->scale_y = (double)4 / HGHT;
	window->cx = 0.5;
	window->cy = 0.5;
}

int		main(int argc, char **argv)
{
	t_mlx				mlx;
	t_key_hook_param	param;
	t_image				image;
	t_window			window;

	if (!error_argc(argc))
		return (1);
	if (!error_argv(argv, &param))
		return (1);
	init(&window);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WDTH, HGHT, "fractol");
	image = new_image(&mlx);
	param.mlx = &mlx;
	param.image = &image;
	param.window = &window;
	param.window->detail = 30;
	(*param.f)(&image, &window);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, image.img_ptr, 0, 0);
	mlx_mouse_hook(mlx.win_ptr, &mouse_hook, &param);
	mlx_hook(mlx.win_ptr, 2, 5, &key_hook, &param);
	mlx_hook(mlx.win_ptr, 6, 5, &mouse_move, &param);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
