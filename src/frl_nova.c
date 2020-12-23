/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_nova.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 08:49:19 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/23 13:17:46 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "math.h"

static t_complex	ft_cderivative (t_complex z)
{
	t_complex	temp;

	temp = ft_cmultiply(z, z);
	temp.re = 3 * temp.re;
	temp.im = 3 * temp.im;
	return (temp);
}

static t_complex	frl_newtons_method(t_complex z)
{
	z = ft_cpow3(z);
	z.re = z.re - 1.0;
	z.im = z.im - 0.0;
	return (z);
}

void				frl_nova(t_data *data, t_uv screen, t_cam *cam)
{
	t_complex		roots[3];
	t_complex		z_div;
	t_complex		z;
	int				i;
	int				k;
	t_complex		diff;
	t_complex		c;

	i = 0;
	roots[0].re = 1.0;
	roots[0].im = 0.0;
	roots[1].re = -0.5;
	roots[1].im = sin(2.0 * PI / 3.0);
	roots[2].re = -0.5;
	roots[2].im = -sin(2.0 * PI / 3.0);
	z = frl_normalize_coordinates(screen.u, screen.v, cam);
	c = z;
	while (i < cam->max_iter)
	{
		z_div = ft_cdivision(frl_newtons_method(z), ft_cderivative(z));
		z.re -= 0.5 * z_div.re;
		z.im -= 0.5 * z_div.im;
		z.re += c.re;
		z.im += c.im;
		k = 0;
		while (k < 3)
		{
			diff = ft_csub(z, roots[k]);
			if (diff.re * diff.re + diff.im * diff.im < 0.00001)
			{
				g42_mlx_pixel_put(data, screen.u, screen.v, frl_colour_scheme(i, cam));
				return ;
			}
			k++;
		}
		i++;
	}
	g42_mlx_pixel_put(data, screen.u, screen.v, black);
}
