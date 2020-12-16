/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:35:51 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/16 15:25:02 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../mlx_linux/mlx.h"

int		frl_reset(int buttoncode, t_vars *vars)
{
	if (buttoncode == KEY_4)
	{
		vars->cur.change = 1;
		vars->cur.reset_change = 1;
		frl_init_camera(&vars->cur);
	}
	return (0);
}
