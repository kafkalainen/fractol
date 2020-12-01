/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_scale_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:20:11 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/01 15:14:35 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "frl.h"
#include "../libft/libft.h"

int frl_scale_object(int keycode, t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->data->img);
	vars->data->img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->data->addr = mlx_get_data_addr(vars->data->img,
										 &vars->data->bpp, &vars->data->llen, &vars->data->endian);
	if (keycode == KEY_1)
	{
		g42_mod_pts(vars->map, &g42_scale_point, 1.1);
		vars->cur.dist *= 1.1;
	}
	if (keycode == KEY_2)
	{
		g42_mod_pts(vars->map, &g42_scale_point, 0.9);
		vars->cur.dist *= 0.9;
	}
	frl_translate_coordinates(vars->map, &vars->cur);
	frl_draw_wire(vars->data, vars->map, vars->map->screen, vars->cur.colour);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
	return (0);
}
