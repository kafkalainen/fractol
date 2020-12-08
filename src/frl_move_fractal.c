/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_move_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:58:36 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/03 18:39:28 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../mlx_linux/mlx.h"
#include "stdio.h"

int		frl_move_fractal(int keycode, t_vars *vars)
{
	t_uv change;

	change.u = 0;
	change.v = 0;
	mlx_destroy_image(vars->mlx, vars->data->img);
	vars->data->img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->data->addr = mlx_get_data_addr(vars->data->img, &vars->data->bpp,
		&vars->data->llen, &vars->data->endian);
	if (keycode == UP || keycode == DOWN)
	{
		change.v = keycode == UP ? 15 : -15;
		vars->cur.offset.v += change.v;
	}
	if (keycode == RIGHT || keycode == LEFT)
	{
		change.u = keycode == RIGHT ? 15 : -15;
		vars->cur.offset.u += change.u;
	}
	printf("Current set is: %s", vars->set);
	printf("Current x offset is: %d", vars->cur.offset.u);
	printf("Current y offset is: %d", vars->cur.offset.v);
	frl_draw_fractal(&vars->cur, vars->data, vars->set);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
	return (0);
}
