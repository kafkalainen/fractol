/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_change_colours.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 09:20:36 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/16 18:43:03 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../mlx_linux/mlx.h"
#include <stdlib.h>
#include "../libft/libft.h"

static t_rgb		frl_rotate_colours(t_rgb in)
{
	in.b += 10;
	if (in.b > 255)
		in.b = 0;
	return (in);
}

int					frl_change_colours(int buttoncode, t_vars *vars)
{
	if (buttoncode == KEY_2)
	{
		vars->cur.change = 1;
		vars->cur.colour = frl_rotate_colours(vars->cur.colour);
	}
	return (0);
}
