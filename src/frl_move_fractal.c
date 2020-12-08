/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_move_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:58:36 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/08 15:14:37 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../mlx_linux/mlx.h"
#include "stdio.h"

int		frl_move_fractal(int keycode, t_vars *vars)
{
	t_vec3 change;

	change.x = 0.0;
	change.y = 0.0;
	mlx_destroy_image(vars->mlx, vars->data->img);
	vars->data->img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->data->addr = mlx_get_data_addr(vars->data->img, &vars->data->bpp,
		&vars->data->llen, &vars->data->endian);
	if (keycode == UP || keycode == DOWN)
	{
		change.y = keycode == UP ? 0.003 : -0.003;
		vars->cur.offset.y += change.y;
	}
	if (keycode == RIGHT || keycode == LEFT)
	{
		change.x = keycode == RIGHT ? -0.003 : 0.003;
		vars->cur.offset.x += change.x;
	}
	// printf("Current set is: %s", vars->set);
	// printf("Current x offset is: %f", vars->cur.offset.x);
	// printf("Current y offset is: %f", vars->cur.offset.y);
	frl_draw_fractal(&vars->cur, vars->data, vars->set);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
	return (0);
}