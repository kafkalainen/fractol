/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_image_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:57:10 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 16:30:27 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../mlx_linux/mlx.h"

int		frl_image_loop(t_vars *vars)
{
	if (vars && vars->cur.change)
	{
		mlx_destroy_image(vars->mlx, vars->data->img);
		vars->data->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
		vars->data->addr = mlx_get_data_addr(vars->data->img, &vars->data->bpp,
			&vars->data->llen, &vars->data->endian);
		frl_draw_fractal(&vars->cur, vars->data, vars->set);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
		vars->cur.change = 0;
	}
	return (0);
}
