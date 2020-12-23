/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_nova.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 08:49:19 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/23 16:54:56 by jnivala          ###   ########.fr       */
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

//x**3 - 3x**2 + 3x - 1
static t_complex	frl_newtons_method(t_complex z)
{
	t_complex	z_pow_3;
	t_complex	z_pow_2;

	z_pow_3 = ft_cpow3(z);
	z_pow_2 = ft_cmultiply(z, z);
	z_pow_2.re *= 3;
	z_pow_2.im *= 3;
	z.re *= 3;
	z.im *= 3;
	z.re = z_pow_3.re - z_pow_2.re + z.re - 1.0;
	z.im = z_pow_3.im - z_pow_2.im + z.im;
	return (z);
}

void				frl_nova(t_data *data, t_uv screen, t_cam *cam)
{
	t_complex		z_div;
	t_complex		z;
	int				i;
	t_complex		c;
	t_complex		diff;

	i = 0;
	//z.re = 0.0;
	//z.im = 0.0;
	c.re = 0.5;
	c.im = 0.4;
	z = frl_normalize_coordinates(screen.u, screen.v, cam);
	while (i < cam->max_iter)
	{
		z_div = ft_cdivision(frl_newtons_method(z), ft_cderivative(z));
		z.re = z.re - z_div.re + c.re;
		z.im = z.im - z_div.im + c.im;
		diff.re = z.re - 1.0;
		diff.im = z.im;
		if (diff.re * diff.re + diff.im * diff.im < 0.000001)
		{
			g42_mlx_pixel_put(data, screen.u, screen.v, frl_colour_scheme(i, cam));
			return ;
		}
		i++;
	}
	g42_mlx_pixel_put(data, screen.u, screen.v, black);
}
