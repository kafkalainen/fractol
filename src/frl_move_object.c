/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_move_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:41:15 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/01 15:14:35 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "frl.h"
#include "../libft/libft.h"

int frl_move_object(int keycode, t_vars *vars)
{
	t_vec3 a;

	a.x = 0.0;
	a.y = 0.0;
	a.z = 0.0;
	mlx_destroy_image(vars->mlx, vars->data->img);
	vars->data->img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->data->addr = mlx_get_data_addr(vars->data->img, &vars->data->bpp,
										 &vars->data->llen, &vars->data->endian);
	if (keycode == UP || keycode == DOWN)
	{
		a.y = keycode == UP ? 15.0 : -15.0;
		vars->cur.vector.y += a.y;
		g42_mod_vec(vars->map, &g42_translate, a);
	}
	if (keycode == RIGHT || keycode == LEFT)
	{
		a.x = keycode == RIGHT ? 15.0 : -15.0;
		vars->cur.vector.x += a.x;
		g42_mod_vec(vars->map, &g42_translate, a);
	}
	frl_translate_coordinates(vars->map, &vars->cur);
	frl_draw_wire(vars->data, vars->map, vars->map->screen, vars->cur.colour);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
	return (0);
}
