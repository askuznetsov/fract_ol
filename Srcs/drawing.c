/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 14:29:56 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/19 14:31:16 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		f1(unsigned char *pxl, double intens, unsigned char color)
{
	if (intens < 0.4)
		pxl[0] = 250 * intens;
	else if (intens < 0.5)
	{
		intens = (intens - 0.35) * 10 / 1.5;
		color = (unsigned char)(255 * intens);
		pxl[0] = 255;
		pxl[1] = color;
		pxl[2] = color;
	}
	else if (intens < 0.6)
	{
		intens = (intens - 0.45) * 10 / 1.5;
		color = (unsigned char)(255 * intens);
		if (intens > 0.45)
		{
			pxl[0] = color;
			pxl[1] = color;
		}
	}
}

void		f2(unsigned char *pixel, double intens, unsigned char color)
{
	if (intens < 0.7)
	{
		intens = (intens - 0.55) * 10 / 1.5;
		color = (unsigned char)(255 * intens);
		pixel[0] = 0;
		pixel[1] = color;
		pixel[2] = color;
	}
	else if (intens < 0.75)
	{
		intens = (intens - 0.65) * 10;
		color = (unsigned char)(255 * intens);
		pixel[0] = color;
		pixel[1] = color;
	}
	else if (intens < 1)
	{
		intens = (intens - 0.75) * 4;
		color = (unsigned char)(255 * intens);
		pixel[1] = color;
		pixel[2] = color;
	}
}
