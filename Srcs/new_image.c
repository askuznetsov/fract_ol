/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 17:16:35 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/14 17:19:55 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		*image_point(t_image *img, int x, int y)
{
	void	*image;
	int		size_line;
	int		temp;

	image = img->img_data;
	size_line = img->sz_ln;
	temp = img->bts_pr_pxl;
	return (((int*)(image + size_line * y + temp * x / 8)));
}

t_image	new_image(void *mlx_ptr)
{
	t_image	image;

	image.img_ptr = mlx_new_image(mlx_ptr, WDTH, HGHT);
	image.img_data = mlx_get_data_addr(image.img_ptr, &image.bts_pr_pxl,
										&image.sz_ln, &image.ndn);
	return (image);
}
