/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_colour_scheme.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 08:48:55 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/09 09:55:15 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"

int		frl_colour_scheme(int i, int g, int b, int mode)
{
	t_rgb	rgb;
	int		colour;

	colour = 0;
	if (mode == 1) {
		rgb.r = i % 256;
		rgb.g = g;
		rgb.b = b;
		colour = g42_rgb_to_hex(g42_hsv_to_rgb(g42_rgb_to_hsv(rgb)));
		return (colour);
	} else if (mode == 2) {
		return (colour = g42_get_colours(i));
	} else if (mode == 3) {
		if (b > 0) {
			colour = white;
		} else {
			colour = black;
		}
	} else {
		return (colour);
	}
	return (colour);
}
