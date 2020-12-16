/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_change_colour_mode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:39:56 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/16 15:17:09 by jnivala          ###   ########.fr       */
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
	if (buttoncode == KEY_1)
	{
		vars->cur.mode_change = 1;
		vars->cur.change = 1;
		vars->cur.mode = frl_colour_mode_switch(vars->cur.mode);
	}
	return (0);
}
