/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_tricorn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:14:12 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/22 14:24:48 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "frl.h"

void		frl_tricorn(t_data *data, t_uv screen, t_cam *cam)
{
	t_complex		c;
	t_dual			z;
	double			z_re_temp;
	int				i;

	i = 0;
	c = frl_normalize_coordinates(screen.u, screen.v, cam);
	z.one.re = 0.0;
	z.one.im = 0.0;
	z.sq.re = 0.0;
	z.sq.im = 0.0;
	while (z.sq.re + z.sq.im < 4.0 && i < cam->max_iter)
	{
		z_re_temp = z.sq.re - z.sq.im + c.re;
		z.one.im = -2.0 * z.one.re * z.one.im + c.im;
		z.one.re = z_re_temp;
		z.sq.re = z.one.re * z.one.re;
		z.sq.im = z.one.im * z.one.im;
		i++;
	}
	g42_mlx_pixel_put(data, screen.u, screen.v, frl_colour_scheme(i, cam));
}
