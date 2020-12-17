/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_draw_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:53:34 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/17 12:05:35 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "frl.h"

int		frl_draw_fractal(t_cam *cam, t_data *data, char *str)
{
	frl_draw_menu(data, g42_rgb_to_hex(cam->colour), cam);
	if (ft_strequ("mandelbrot", str))
	{
		frl_paint_current_fractal(data, cam, &frl_mandelbrot);
		return (0);
	}
	else if (ft_strequ("julia", str))
	{
		frl_paint_current_fractal(data, cam, &frl_julia);
		return (0);
	}
	else if (ft_strequ("burningship", str))
	{
		frl_paint_current_fractal(data, cam, &frl_burningship);
		return (0);
	}
	else
	{
		ft_putendl_fd("ERROR: Don't have that set.", 2);
		ft_putendl_fd(str, 2);
		return (1);
	}
}
