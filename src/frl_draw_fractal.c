/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_draw_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:53:34 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/23 15:30:33 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "frl.h"

int			frl_draw_fractal(t_cam *cam, t_data *data, char *str)
{
	cam->mult.x = 2.0;
	cam->mult.y = 1.5;
	frl_draw_menu(data, g42_rgb_to_hex(cam->colour), cam);
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
