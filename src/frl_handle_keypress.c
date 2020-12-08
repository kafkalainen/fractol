/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_handle_keypress.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 08:43:38 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/08 18:14:01 by jnivala          ###   ########.fr       */
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
	if (vars && (keycode == DOWN || keycode == UP || keycode == LEFT || keycode == RIGHT))
		frl_move_fractal(keycode, vars);
	return (0);
}
