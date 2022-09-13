/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 18:06:00 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/19 16:24:11 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		error_argc(int nbr)
{
	if (nbr != 2)
	{
		ft_putstr("Error.\nAvailable fractals:\n1.Mandelbrot\n"
			"2.Julia\n3.Burning ship\n"
			"4.Fish\n5.Ancients\n6.Web\n7.Rose\n");
		return (0);
	}
	return (1);
}

int		error_argv(char **argv, t_key_hook_param *param)
{
	if (!ft_strcmp(argv[1], "Mandelbrot"))
		param->f = &mandelbrot;
	else if (!ft_strcmp(argv[1], "Julia"))
		param->f = &julia;
	else if (!ft_strcmp(argv[1], "Burning ship"))
		param->f = &burning_ship;
	else if (!ft_strcmp(argv[1], "Fish"))
		param->f = &fish;
	else if (!ft_strcmp(argv[1], "Ancients"))
		param->f = &anc;
	else if (!ft_strcmp(argv[1], "Web"))
		param->f = &web;
	else if (!ft_strcmp(argv[1], "Rose"))
		param->f = &rose;
	else
	{
		ft_putstr("Error.\nAvailable fractals:\n1.Mandelbrot\n"
			"2.Julia\n3.Burning ship\n"
			"4.Fish\n5.Ancients\n6.Web\n7.Rose");
		return (0);
	}
	return (1);
}
