/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_draw_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:53:34 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/09 11:35:19 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "frl.h"

int		frl_draw_fractal(t_cam *cam, t_data *data, char *str)
{
	if (ft_strequ("mandelbrot", str)) {
		frl_paint_current_fractal(data, cam, &frl_mandelbrot);
		frl_draw_menu(data, cam->colour);
		return (0);
	} else if (ft_strequ("julia", str)) {
		frl_paint_current_fractal(data, cam, &frl_julia);
		frl_draw_menu(data, cam->colour);
		return (0);
	} else {
		ft_putendl_fd("ERROR: Don't have that set.", 2);
		ft_putendl_fd(str, 2);
		return (1);
	}
}
