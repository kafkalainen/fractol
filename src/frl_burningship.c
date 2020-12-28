/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_burningship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:33:59 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/28 12:58:55 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../libft/libft.h"

void	frl_burningship(t_data *data, t_uv screen, t_cam *cam)
{
	t_complex		c;
	t_complex		z;
	t_complex		temp;
	int				i;

	i = 0;
	c = frl_normalize_coordinates(screen.u, screen.v, cam);
	z = c;
	while (z.re * z.re + z.im * z.im < 4.0 && i < cam->max_iter)
	{
		temp.re = z.re * z.re - z.im * z.im + c.re;
		z.im = ft_dabs(2.0 * z.re * z.im) + c.im;
		z.re = temp.re;
		i++;
	}
	g42_mlx_pixel_put(data, screen.u, screen.v, frl_colour_scheme(i, cam));
}
