/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_zoom_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:39:56 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 14:24:31 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../mlx_linux/mlx.h"

int				frl_zoom_fractal(int buttoncode, int x, int y, t_vars *vars)
{
	t_complex	complex;

	mlx_destroy_image(vars->mlx, vars->data->img);
	vars->data->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	vars->data->addr = mlx_get_data_addr(vars->data->img, &vars->data->bpp,
		&vars->data->llen, &vars->data->endian);
	if (buttoncode == ZOOM_IN || buttoncode == ZOOM_OUT)
	{
		complex = frl_normalize_coordinates(x, y, &vars->cur);
		vars->cur.offset.x = complex.re;
		vars->cur.offset.y = complex.im;
		if (buttoncode == ZOOM_IN)
			vars->cur.dist *= 1.1;
		else
			vars->cur.dist *= 0.9;
	}
	frl_draw_fractal(&vars->cur, vars->data, vars->set);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
	return (0);
}
