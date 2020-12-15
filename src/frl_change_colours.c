/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_change_colours.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 09:20:36 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 20:39:18 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../mlx_linux/mlx.h"
#include <stdlib.h>
#include "../libft/libft.h"

static t_rgb		frl_rotate_colours(t_rgb in)
{
	t_rgb out;

	if (in.g + 10 < 255 && in.g + 10 >= 0)
		out.g = in.g + 10;
	else
		out.g = 0;
	return (out);
}

int					frl_change_colours(int buttoncode, t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->data->img);
	vars->data->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	vars->data->addr = mlx_get_data_addr(vars->data->img, &vars->data->bpp,
		&vars->data->llen, &vars->data->endian);
	if (buttoncode == KEY_2)
	{
		vars->cur.change = 1;
		vars->cur.colour = frl_rotate_colours(vars->cur.colour);
	}
	frl_draw_fractal(&vars->cur, vars->data, vars->set);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
	return (0);
}
