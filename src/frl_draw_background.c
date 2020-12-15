/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_draw_background.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:46:45 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 13:07:29 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"

int frl_draw_background(t_data *data)
{
	t_uv pixel;

	pixel.v = 0;
	while (pixel.v < WIN_H)
	{
		pixel.u = 0;
		while (pixel.u < WIN_W)
		{
			g42_mlx_pixel_put(data, pixel.u, pixel.v, 0xff1f1f1f);
			pixel.u++;
		}
		pixel.v++;
	}
	return (0);
}
