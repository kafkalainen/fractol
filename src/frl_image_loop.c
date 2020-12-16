/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_image_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:57:10 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/16 15:20:26 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../mlx_linux/mlx.h"
#include <stdlib.h>

int		frl_image_loop(t_vars *vars)
{
	if (vars && vars->win)
	{
		if (vars->cur.change == 1)
		{
			frl_draw_fractal(&vars->cur, vars->data, vars->set);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
			vars->cur.change = 0;
		}
	}
	return (0);
}
