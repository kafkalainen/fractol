/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_move_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:58:36 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/16 15:21:05 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../mlx_linux/mlx.h"

int		frl_move_fractal(int keycode, t_vars *vars)
{
	t_vec3 change;

	change.x = 0.0;
	change.y = 0.0;
	if (keycode == UP || keycode == DOWN)
	{
		vars->cur.move_change = 1;
		vars->cur.change = 1;
		change.y = keycode == UP ? 0.03 : -0.03;
		vars->cur.offset.y += change.y / vars->cur.dist;
	}
	if (keycode == RIGHT || keycode == LEFT)
	{
		vars->cur.move_change = 1;
		vars->cur.change = 1;
		change.x = keycode == RIGHT ? -0.03 : 0.03;
		vars->cur.offset.x += change.x / vars->cur.dist;
	}
	return (0);
}
