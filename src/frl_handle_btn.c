/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_handle_btn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:59:22 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 12:59:24 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"

int	frl_handle_btn(int buttoncode, int x, int y, t_vars *vars)
{
	if (x && y && vars && (buttoncode == ZOOM_OUT || buttoncode == ZOOM_IN))
		frl_zoom_fractal(buttoncode, x, y, vars);
	return (0);
}
