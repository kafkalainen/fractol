/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_handle_enter_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:51:27 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/16 16:23:34 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../mlx_linux/mlx.h"

int		frl_handle_enter_window(t_vars *vars)
{
	if (vars)
		mlx_loop_hook(vars->mlx, frl_image_loop, vars);
	return (0);
}
