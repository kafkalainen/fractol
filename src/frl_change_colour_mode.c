/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_change_colour_mode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:39:56 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 13:49:02 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../mlx_linux/mlx.h"
#include <stdlib.h>
#include "../libft/libft.h"

static int		frl_colour_mode_switch(int i)
{
	if (i == 1)
		return (2);
	else if (i == 2)
		return (3);
	else if (i == 3)
		return (4);
	else if (i == 4)
		return (1);
	else
		return (0);
}

int				frl_change_colour_mode(int buttoncode, t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->data->img);
	vars->data->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	vars->data->addr = mlx_get_data_addr(vars->data->img, &vars->data->bpp,
		&vars->data->llen, &vars->data->endian);
	if (buttoncode == KEY_1)
		vars->cur.mode = frl_colour_mode_switch(vars->cur.mode);
	frl_draw_fractal(&vars->cur, vars->data, vars->set);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
	return (0);
}
