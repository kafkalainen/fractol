/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_mandelbrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:30:09 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/08 14:45:43 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "pthread.h"

void		frl_mandelbrot(t_data *data, t_uv screen, t_cam *cam)
{
	t_complex		c;
	t_dual			new;
	int				i;

	c.re = (screen.u - WIN_WIDTH / 2.0) * (4.0 / WIN_WIDTH) + cam->offset.x;
	c.im = (screen.v - WIN_HEIGHT / 2.0) * (4.0 / WIN_WIDTH) + cam->offset.y;
	i = 0;
	new.one.re = 0;
	new.one.im = 0;
	new.sq.re = 0;
	new.sq.im = 0;
	while (new.sq.re + new.sq.im <= 4 && i < 1000)
	{
		new.one.im = 2 * new.one.re * new.one.im + c.im;
		new.one.re = new.sq.re - new.sq.im + c.re;
		new.sq.re = new.one.re * new.one.re;
		new.sq.im = new.one.im * new.one.im;
		i++;
	}
	if (i < MAX_ITER)
		g42_mlx_pixel_put(data, screen.u, screen.v, frl_colour_scheme(i, 115, 225, 1));
	else
		g42_mlx_pixel_put(data, screen.u, screen.v, frl_colour_scheme(i, 115, 0, 1));
}
