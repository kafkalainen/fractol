/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_magnet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:30:55 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/23 15:35:59 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "frl.h"
#include "../libft/libft.h"

/*(z ** 2 + C - 1)*/
static t_complex	frl_dividee(t_complex z, t_complex c)
{
	t_complex	result;

	result = ft_cmultiply(z, z);
	result.re += c.re - 1;
	result.im += c.im;
	result = ft_cmultiply(result, result);
	return (result);
}

/*(2 * z + C - 2)*/
static t_complex	frl_divisor(t_complex z, t_complex c)
{
	z.re = 2 * z.re;
	z.im = 2 * z.im;
	z = ft_cadd(z, c);
	z.re -= 2;
	z = ft_cmultiply(z, z);
	return (z);
}

/*(z ** 2 + C - 1) / (2 * z + C - 2)**2*/
void				frl_magnet(t_data *data, t_uv screen, t_cam *cam)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	z.re = 0.0;
	z.im = 0.0;
	c = frl_normalize_coordinates(screen.u, screen.v, cam);
	c.re *= 2.0;
	c.im *= 2.0;
	while (i < cam->max_iter)
	{
		z = ft_cdivision(frl_dividee(z, c), frl_divisor(z, c));
		if (z.re * z.re + z.im * z.im > 16.0)
		{
			g42_mlx_pixel_put(data, screen.u, screen.v, frl_colour_scheme(i, cam));
			return ;
		}
		i++;
	}
	g42_mlx_pixel_put(data, screen.u, screen.v, frl_colour_scheme(0, cam));
}
