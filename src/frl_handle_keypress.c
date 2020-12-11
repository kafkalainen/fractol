/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_handle_keypress.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 08:43:38 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/10 16:39:52 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "frl.h"

int frl_handle_keypress(int keycode, t_vars *vars)
{
	if (vars && keycode == ESC)
		vars = frl_clean(&vars);
	if (vars && (keycode == DOWN || keycode == UP
		|| keycode == LEFT || keycode == RIGHT))
		frl_move_fractal(keycode, vars);
	if (vars && keycode == KEY_1)
		frl_change_colour_mode(keycode, vars);
	if (vars && keycode == KEY_2)
		frl_change_colours(keycode, vars);
	if (vars && keycode == KEY_3)
		frl_reset_colour(keycode, vars);
	if (vars && keycode == KEY_4)
		frl_reset(keycode, vars);
	return (0);
}
