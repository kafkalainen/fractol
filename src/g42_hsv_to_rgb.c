/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_hsv_to_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:40:05 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/16 18:27:29 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"
#include <math.h>

static t_rgb		g42_first_half_colours(t_hsv hsv, t_col_trans col)
{
	t_rgb		rgb;

	if (hsv.h >= 0.0 && hsv.h < 60.0)
	{
		rgb.r = (int)((col.c + col.m) * 255);
		rgb.g = (int)((col.x + col.m) * 255);
		rgb.b = 0;
	}
	else if (hsv.h >= 60.0 && hsv.h < 120.0)
	{
		rgb.r = (int)((col.x + col.m) * 255);
		rgb.g = (int)((col.c + col.m) * 255);
		rgb.b = 0;
	}
	else
	{
		rgb.r = 0;
		rgb.g = (int)((col.c + col.m) * 255);
		rgb.b = (int)((col.x + col.m) * 255);
	}
	return (rgb);
}

static t_rgb		g42_second_half_colours(t_hsv hsv, t_col_trans col)
{
	t_rgb		rgb;

	if (hsv.h >= 180.0 && hsv.h < 240.0)
	{
		rgb.r = 0;
		rgb.g = (int)((col.x + col.m) * 255);
		rgb.b = (int)((col.c + col.m) * 255);
	}
	else if (hsv.h >= 240.0 && hsv.h < 300.0)
	{
		rgb.r = (int)((col.x + col.m) * 255);
		rgb.g = 0;
		rgb.b = (int)((col.c + col.m) * 255);
	}
	else
	{
		rgb.r = (int)((col.c + col.m) * 255);
		rgb.g = 0;
		rgb.b = (int)((col.x + col.m) * 255);
	}
	return (rgb);
}

t_rgb				g42_hsv_to_rgb(t_hsv hsv)
{
	t_rgb		rgb;
	t_col_trans	cmx;

	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	cmx.c = hsv.s * hsv.v;
	cmx.x = cmx.c * (1 - fabs(fmod(hsv.h / 60.0, 2.0) - 1));
	cmx.m = hsv.v - cmx.c;
	if (hsv.h > 360.0 || hsv.h < 0.0
	|| hsv.s > 1.0 || hsv.s < 0.0
	|| hsv.v > 1.0 || hsv.v < 0.0)
		return (rgb);
	if (hsv.h >= 0.0 && hsv.h < 180.0)
		rgb = g42_first_half_colours(hsv, cmx);
	if (hsv.h >= 180.0 && hsv.h < 360.0)
		rgb = g42_second_half_colours(hsv, cmx);
	return (rgb);
}
