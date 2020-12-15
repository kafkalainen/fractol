/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:14:18 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 13:51:11 by jnivala          ###   ########.fr       */
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
	c = cam->shape;
	new = frl_normalize_coordinates(screen.u, screen.v, cam);
	while (new.re * new.re + new.im * new.im < 4.0 && i < cam->max_iter)
	{
		old = new;
		new.re = old.re * old.re - old.im * old.im + c.re;
		new.im = 2.0 * old.re * old.im + c.im;
		i++;
	}
	g42_mlx_pixel_put(data, screen.u, screen.v, frl_colour_scheme(i, cam));
}
