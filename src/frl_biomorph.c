/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_biomorph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 02:36:33 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/28 10:49:17 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include <math.h>

void		frl_biomorph(t_data *data, t_uv screen, t_cam *cam)
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
		z.re = a.re * (a.re * a.re - 3 * a.im * a.im) + c.re;
		z.im = a.im * (3 * a.re * a.re - a.im * a.im) + c.im;
		if (z.re * z.re + z.im * z.im > 100.0 ||
			ft_dabs(z.re) > 10.0 || ft_dabs(z.im) > 10.0)
			break ;
		i++;
	}
	if (ft_dabs(z.re) < 10.0 || ft_dabs(z.im) < 10.0)
		i = cam->max_iter - i - 1;
	g42_mlx_pixel_put(data, screen.u, screen.v, frl_colour_scheme(i, cam));
}
