/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_change_colours.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 09:20:36 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/16 15:19:44 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../mlx_linux/mlx.h"
#include <stdlib.h>
#include "../libft/libft.h"

static t_rgb		frl_rotate_colours(t_rgb in)
{
	t_rgb out;

	if (in.g + 10 < 255 && in.g + 10 > 0)
		out.g = in.g + 10;
	else
		out.g = 0;
	// if (in.g = 0 && in.b + 10 < 255 && in.b + 10 > 0)
	return (out);
}

int					frl_change_colours(int buttoncode, t_vars *vars)
{
	if (buttoncode == KEY_2)
	{
		vars->cur.colour_change = 1;
		vars->cur.colour = frl_rotate_colours(vars->cur.colour);
	}
	ft_putstr("Fired change colour: ");
	ft_putnbr((int)vars->cur.colour_change);
	ft_putchar('\n');
	return (0);
}
