/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:35:51 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 20:42:02 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../mlx_linux/mlx.h"

int		frl_reset(int buttoncode, t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->data->img);
	vars->data->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	vars->data->addr = mlx_get_data_addr(vars->data->img, &vars->data->bpp,
		&vars->data->llen, &vars->data->endian);
	if (buttoncode == KEY_4)
	{
		vars->cur.change = 1;
		frl_init_camera(&vars->cur);
	}
	frl_draw_fractal(&vars->cur, vars->data, vars->set);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
	return (0);
}
