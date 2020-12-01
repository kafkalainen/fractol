/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 13:18:55 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/01 15:14:35 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../libft/libft.h"

void frl_draw_line(t_data *data, t_uv p0, t_uv p1, int colour)
{
	t_uv delta;

	delta.u = ft_abs(p1.u - p0.u);
	delta.v = ft_abs(p1.v - p0.v);
	if (delta.u == 0 || delta.v == 0)
		g42_mlx_draw_x_y_line(data, p0, p1, colour);
	else
		g42_draw_line_bre(data, p0, p1, colour);
}
