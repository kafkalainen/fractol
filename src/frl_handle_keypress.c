/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_handle_keypress.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 08:43:38 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/03 17:58:13 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "frl.h"

int frl_handle_keypress(int keycode, t_vars *vars)
{
	if (vars && keycode == ESC)
	{
		vars = frl_clean(&vars);
		exit(EXIT_SUCCESS);
	}
	// if (vars && (keycode == KEY_D || keycode == KEY_W || keycode == KEY_A || keycode == KEY_S ||
	// 			 keycode == KEY_E || keycode == KEY_Q))
	// 	frl_rotate_object(keycode, vars);
	if (vars && (keycode == DOWN || keycode == UP || keycode == LEFT || keycode == RIGHT))
		frl_move_fractal(keycode, vars);
	// if (vars && (keycode == KEY_1 || keycode == KEY_2))
	// 	frl_scale_object(keycode, vars);
	// if (vars && (keycode == KEY_R || keycode == KEY_H))
	// 	frl_reset_object(keycode, vars);
	// if (vars && keycode == KEY_G)
	// 	frl_iso_object(keycode, vars);
	// if (vars && keycode == KEY_F)
	// 	frl_front_object(keycode, vars);
	if (vars && keycode == KEY_C)
	 	frl_change_colour(keycode, vars);
	// if (vars && (keycode == KEY_3 || keycode == KEY_4))
	// 	frl_manipulate_y(keycode, vars);
	return (0);
}
