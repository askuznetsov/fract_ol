/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 18:06:52 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/19 16:16:32 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WDTH 800
# define HGHT 600

# include "libft.h"
# include <../minilibx_macos/mlx.h>
# include <fcntl.h>

typedef struct	s_window
{
	double		pos_x;
	double		pos_y;
	double		scale_x;
	double		scale_y;
	int			detail;
	double		cx;
	double		cy;
}				t_window;

typedef struct	s_image
{
	void		*img_ptr;
	void		*img_data;
	int			bts_pr_pxl;
	int			sz_ln;
	int			ndn;
}				t_image;

typedef	struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

typedef struct	s_param
{
	t_window	*window;
	t_image		*image;
	double		start_y;
	double		end_y;
	double		width;
}				t_param;

typedef struct	s_key_hook_param
{
	t_mlx		*mlx;
	t_image		*image;
	t_window	*window;
	void		(*f)(t_image *, t_window *);
}				t_key_hook_param;

void			f2(unsigned char *pixel, double intens, unsigned char color);
void			f1(unsigned char *pxl, double intens, unsigned char color);
int				mouse_move(int x, int y, void *par);
void			burning_ship(t_image *image, t_window *window);
void			julia(t_image *image, t_window *window);
int				count_iterations_burn(double cx, double cy, int iterations);
int				count_iterations_julia(t_window *window,
				double x, double y, int iterations);
int				mouse_hook(int key, int x, int y, void *par);
void			mandelbrot(t_image *image, t_window *window);
int				count_iterations(double cx, double cy, int iterations);
int				count_iterations_fish(double cx, double cy, int iterations);
void			fish(t_image *image, t_window *window);
int				count_iterations_anc(double cx, double cy, int iterations);
int				count_iterations_rose(double cx, double cy, int iterations);
int				count_iterations_web(double cx, double cy, int iterations);
void			web(t_image *image, t_window *window);
void			anc(t_image *image, t_window *window);
void			rose(t_image *image, t_window *window);
t_image			new_image(void *mlx_ptr);
int				*image_point(t_image *img, int x, int y);
int				key_hook(int key, t_key_hook_param *param);
int				error_argc(int nbr);
int				error_argv(char **argv, t_key_hook_param *param);
#endif
