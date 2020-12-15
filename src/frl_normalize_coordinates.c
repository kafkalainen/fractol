/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_normalize_coordinates.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 09:43:01 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 21:26:52 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"

t_complex	frl_normalize_coordinates(int x, int y, t_cam *cam)
{
	t_complex	c;

	c.re = 2.0 * (x - 0.5 * WIN_W) / (0.5 * WIN_W * cam->dist)
		+ cam->offset.x;
	c.im = 1.5 * (y - 0.5 * WIN_H) / (0.5 * WIN_H * cam->dist)
		+ cam->offset.y;
	return (c);
}
