/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_draw_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:53:34 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/23 18:28:22 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "frl.h"

void		frl_set_range(t_cam *cam, char *str)
{
	if (ft_strequ("mandelbrot", str) || ft_strequ("newton", str))
	{
		cam->mult.x = 1.75;
		cam->mult.y = 1.3125;
	}
	else
	{
		cam->mult.x = 2.0;
		cam->mult.y = 1.5;
	}
}

int			frl_draw_fractal(t_cam *cam, t_data *data, char *str)
{
	frl_draw_menu(data, g42_rgb_to_hex(cam->colour), cam);
	frl_set_range(cam, str);
	if (ft_strequ("mandelbrot", str))
		frl_paint_current_fractal(data, cam, &frl_mandelbrot);
	else if (ft_strequ("julia", str))
		frl_paint_current_fractal(data, cam, &frl_julia);
	else if (ft_strequ("burningship", str))
		frl_paint_current_fractal(data, cam, &frl_burningship);
	else if (ft_strequ("newton", str))
		frl_paint_current_fractal(data, cam, &frl_newton);
	else if (ft_strequ("nova", str))
		frl_paint_current_fractal(data, cam, &frl_nova);
	else if (ft_strequ("magnet", str))
		frl_paint_current_fractal(data, cam, &frl_magnet);
	else if (ft_strequ("tricorn", str))
		frl_paint_current_fractal(data, cam, &frl_tricorn);
	else
	{
		ft_putendl_fd("ERROR: Don't have that set.", 2);
		ft_putendl_fd(str, 2);
		return (1);
	}
	return (0);
}
