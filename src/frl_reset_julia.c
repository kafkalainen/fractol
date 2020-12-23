/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_reset_julia.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:38:36 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/23 18:49:56 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../mlx_linux/mlx.h"

int		frl_reset_julia(int buttoncode, t_vars *vars)
{
	if (buttoncode == KEY_W)
	{
		if (!vars->cur.toggle)
		{
			mlx_hook(vars->win, MTNNOTIFY, PTRMTNMASK, frl_handle_mov, NULL);
			vars->cur.toggle = 1;
			vars->cur.change = 1;
		}
		else
		{
			mlx_hook(vars->win, MTNNOTIFY, PTRMTNMASK, frl_handle_mov, vars);
			vars->cur.toggle = 0;
		}
	}
	return (0);
}

