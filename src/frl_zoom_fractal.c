/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_zoom_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:39:56 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/22 15:05:33 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"

int				frl_zoom_fractal(int buttoncode, int x, int y, t_vars *vars)
{
	t_complex	complex;

	if (buttoncode == ZOOM_IN || buttoncode == ZOOM_OUT)
	{
		complex = frl_normalize_coordinates(x, y, &vars->cur);
		vars->cur.offset.x = complex.re;
		vars->cur.offset.y = complex.im;
		if (buttoncode == ZOOM_IN)
			vars->cur.dist *= 1.1;
		else
			vars->cur.dist *= 0.9;
		vars->cur.change = 1;
	}
	return (0);
}
