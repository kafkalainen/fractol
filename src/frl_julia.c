/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:14:18 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/04 17:37:42 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"

void	frl_julia(t_data *data, t_uv screen, t_cam *cam)
{
	t_complex		c;
	t_complex		new;
	t_complex		old;
	int				i;

	i = 0;
	c.re = -0.7;
	c.im = 0.27015;
	new.re = 1.5 * (screen.u - WIN_WIDTH / 2) / (0.5 * cam->dist * WIN_WIDTH) + cam->offset.u;
	new.im = (screen.v - WIN_HEIGHT / 2) / (0.5 * cam->dist * WIN_HEIGHT) + cam->offset.v;
	while (new.re * new.re + new.im * new.im  <= 4 && i < MAX_ITER)
	{
		old = new;
		new.re = old.re * old.re - old.im * old.im + c.re;
		new.im = 2 * old.re * old.im + c.im;
		i++;
	}
	if (i < MAX_ITER)
		g42_mlx_pixel_put(data, screen.u, screen.v, frl_colour_scheme(i, 115, 225, 1));
	else
		g42_mlx_pixel_put(data, screen.u, screen.v, frl_colour_scheme(i, 115, 0, 1));
}
