/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_newton.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:52:16 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/23 17:28:56 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "frl.h"

static t_complex	ft_cderivative(t_complex z)
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

static t_complex	frl_cassign(double re, double im)
{
	t_complex	z;

	z.re = re;
	z.im = im;
	return (z);
}

static int			frl_roots(t_complex z)
{
	int				i;
	t_complex		diff;
	t_complex		roots[3];

	i = 0;
	roots[0] = frl_cassign(1.0, 0.0);
	roots[1] = frl_cassign(-0.5, sin(2.0 * PI / 3.0));
	roots[2] = frl_cassign(-0.5, -sin(2.0 * PI / 3.0));
	while (i < 3)
	{
		diff = ft_csub(z, roots[i]);
		if (diff.re * diff.re + diff.im * diff.im < 0.00001)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void				frl_newton(t_data *data, t_uv screen, t_cam *cam)
{
	int				i;
	t_complex		z_div;
	t_complex		z;

	i = 0;
	z = frl_normalize_coordinates(screen.u, screen.v, cam);
	while (i < cam->max_iter)
	{
		z_div = ft_cdivision(frl_newtons_method(z), ft_cderivative(z));
		z = ft_csub(z, z_div);
		if (frl_roots(z))
		{
			g42_mlx_pixel_put(data, screen.u, screen.v,
				frl_colour_scheme(i, cam));
			return ;
		}
		i++;
	}
	g42_mlx_pixel_put(data, screen.u, screen.v, black);
}
