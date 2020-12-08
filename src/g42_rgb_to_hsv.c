/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_rgb_to_hsv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:15:10 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/08 10:30:16 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

static double		g42_ismax(double r, double g, double b)
{
	if (r >= g && r >= b)
		return (r);
	else if (g >= r && g >= b)
		return (g);
	else if (b >= r && b >= g)
		return (b);
	else
		return (r);
}

static double		g42_ismin(double r, double g, double b)
{
	if (r <= g && r <= b)
		return (r);
	else if (g <= r && g <= b)
		return (g);
	else if (b <= r && b <= g)
		return (b);
	else
		return (r);
}

static t_hsv		g42_if_smaller(t_hsv out)
{
	out.s = 0;
	out.h = 0;
	return (out);
}

static t_hsv		g42_calculate_degrees(t_hsv out)
{
	out.h *= 60.0;
	if (out.h < 0.0)
		out.h += 360.0;
	return (out);
}

t_hsv				g42_rgb_to_hsv(t_rgb in)
{
	t_hsv		out;
	double		c_min;
	double		c_max;
	double		delta;

	c_max = g42_ismax(in.r, in.g, in.b);
	c_min = g42_ismin(in.r, in.g, in.b);
	out.v = c_max;
	delta = c_max - c_min;
	if (delta < 0.00001 || c_max <= 0.0)
		return (out = g42_if_smaller(out));
	if (c_max > 0.0)
		out.s = (delta / c_max);
	if (in.r >= c_max)
		out.h = (in.g - in.b) / delta;
	else
	{
		if (in.g >= c_max)
			out.h = 2.0 + (in.b - in.r) / delta;
		else
			out.h = 4.0 + (in.r - in.g) / delta;
	}
	out = g42_calculate_degrees(out);
	return (out);
}
