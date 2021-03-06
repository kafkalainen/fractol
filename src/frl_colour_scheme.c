/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_colour_scheme.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 08:48:55 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/27 15:43:19 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"

static int		frl_lin_map_colour(int i, int g, int max_iter)
{
	t_rgb	c;
	int		new_c;
	t_bound	x1;
	t_bound	x2;

	x1.lower = 0.0;
	x1.upper = max_iter;
	x2.lower = 0.0;
	x2.upper = 255.0;
	c.r = g42_linear_mapping(i, x1, x2);
	c.g = c.r;
	c.b = g;
	new_c = g42_rgb_to_hex(c);
	return (new_c);
}

int				frl_colour_scheme(int i, t_cam *cam)
{
	t_hsv	hsv;

	if (cam->mode == 1)
	{
		if (i >= cam->max_iter)
			return (black);
		hsv.h = ((int)cam->colour.b + i) % 360;
		hsv.s = 1;
		hsv.v = 1;
		return (g42_rgb_to_hex(g42_hsv_to_rgb(hsv)));
	}
	else if (cam->mode == 2)
		return (g42_get_colours(i));
	else if (cam->mode == 3)
	{
		if (i % 2)
			return (white);
		else
			return (black);
	}
	else if (cam->mode == 4)
		return (frl_lin_map_colour(i, cam->colour.b, cam->max_iter));
	else
		return (black);
	return (black);
}
