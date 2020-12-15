/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_mandelbrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:30:09 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 14:33:05 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"

void		frl_mandelbrot(t_data *data, t_uv screen, t_cam *cam)
{
	t_complex		c;
	t_dual			new;
	int				i;

	i = 0;
	c = frl_normalize_coordinates(screen.u, screen.v, cam);
	new.one.re = 0.0;
	new.one.im = 0.0;
	new.sq.re = 0.0;
	new.sq.im = 0.0;
	while (new.sq.re + new.sq.im < 4.0 && i < cam->max_iter)
	{
		new.one.im = 2.0 * new.one.re * new.one.im + c.im;
		new.one.re = new.sq.re - new.sq.im + c.re;
		new.sq.re = new.one.re * new.one.re;
		new.sq.im = new.one.im * new.one.im;
		i++;
	}
	g42_mlx_pixel_put(data, screen.u, screen.v, frl_colour_scheme(i, cam));
}
