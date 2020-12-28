/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_thorn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 02:02:25 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/28 10:49:54 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include <math.h>

void		frl_thorn(t_data *data, t_uv screen, t_cam *cam)
{
	t_complex		z;
	t_complex		a;
	t_complex		c;
	int				i;

	i = 0;
	z = frl_normalize_coordinates(screen.u, screen.v, cam);
	c = cam->shape;
	while (i < cam->max_iter)
	{
		a = z;
		z.re = a.re / cos(a.im) + c.re;
		z.im = a.im / sin(a.re) + c.im;
		if (z.re * z.re + z.im * z.im > 10000.0)
		{
			g42_mlx_pixel_put(data, screen.u, screen.v,
				frl_colour_scheme(i, cam));
			return ;
		}
		i++;
	}
	g42_mlx_pixel_put(data, screen.u, screen.v, black);
}
