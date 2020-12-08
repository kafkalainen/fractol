/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_hsv_to_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:40:05 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/08 11:00:05 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

static t_rgb		g42_if_black(t_hsv in, t_rgb out)
{
	out.r = in.v;
	out.g = in.v;
	out.b = in.v;
	return (out);
}

static t_col_trans	g42_assign_temp(long i, t_hsv in, t_col_trans col)
{
	col.ff = col.hh - i;
	col.p = in.v * (1.0 - in.s);
	col.q = in.v * (1.0 - (in.s * col.ff));
	col.t = in.v * (1.0 - (in.s * (1.0 - col.ff)));
	return (col);
}

static t_rgb		g42_first_half_colours(long i, t_hsv in, t_col_trans col)
{
	t_rgb out;

	if (i == 0)
	{
		out.r = in.v;
		out.g = col.t;
		out.b = col.p;
		return (out);
	}
	else if (i == 1)
	{
		out.r = col.q;
		out.g = in.v;
		out.b = col.p;
		return (out);
	}
	else
	{
		out.r = col.p;
		out.g = in.v;
		out.b = col.t;
		return (out);
	}
}

static t_rgb		g42_second_half_colours(long i, t_hsv in, t_col_trans col)
{
	t_rgb out;

	if (i == 3)
	{
		out.r = col.p;
		out.g = col.q;
		out.b = in.v;
		return (out);
	}
	else if (i == 4)
	{
		out.r = col.t;
		out.g = col.p;
		out.b = in.v;
		return (out);
	}
	else
	{
		out.r = in.v;
		out.g = col.p;
		out.b = col.q;
		return (out);
	}
}

t_rgb				g42_hsv_to_rgb(t_hsv in)
{
	t_col_trans		col;
	long			i;
	t_rgb			out;

	if (in.s <= 0.0)
	{
		return (g42_if_black(in, out));
	}
	col.hh = in.h;
	col.hh = col.hh >= 360.0 ? 0.0 : col.hh;
	col.hh /= 60.0;
	i = (long)col.hh;
	col = g42_assign_temp(i, in, col);
	if (i == 0 || i == 1 || i == 2)
		return (out = g42_first_half_colours(i, in, col));
	else if (i == 3 || i == 4 || i == 5)
		return (out = g42_second_half_colours(i, in, col));
	else
	{
		out.r = in.v;
		out.g = col.p;
		out.b = col.q;
	}
	return (out);
}
