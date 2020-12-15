/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_burningship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:33:59 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 14:33:15 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../libft/libft.h"

void	frl_burningship(t_data *data, t_uv screen, t_cam *cam)
{
	t_complex		c;
	t_complex		new;
	t_complex		temp;
	int				i;

	i = 0;
	c = frl_normalize_coordinates(screen.u, screen.v, cam);
	new = c;
	while (new.re * new.re + new.im * new.im < 4.0 && i < cam->max_iter)
	{
		temp.re = new.re * new.re - new.im * new.im + c.re;
		new.im = ft_dabs(2.0 * new.re * new.im) + c.im;
		new.re = temp.re;
		i++;
	}
	g42_mlx_pixel_put(data, screen.u, screen.v, frl_colour_scheme(i, cam));
}
