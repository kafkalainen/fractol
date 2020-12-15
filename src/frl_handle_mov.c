/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_handle_mov.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:59:38 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 13:10:07 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"

int		frl_handle_mov(int x, int y, t_vars *vars)
{
	if (vars && x && y && ft_strequ(vars->set, "julia"))
	{
		mlx_destroy_image(vars->mlx, vars->data->img);
		vars->data->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
		vars->data->addr = mlx_get_data_addr(vars->data->img,
			&vars->data->bpp, &vars->data->llen, &vars->data->endian);
		vars->cur.shape = frl_normalize_coordinates(x, y, &vars->cur);
		frl_draw_fractal(&vars->cur, vars->data, vars->set);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
	}
	return (0);
}
