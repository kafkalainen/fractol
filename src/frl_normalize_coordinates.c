/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_normalize_coordinates.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 09:43:01 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/10 09:43:43 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"

t_complex	frl_normalize_coordinates(int x, int y, t_cam *cam)
{
	t_complex	c;

	c.re = 1.5 * (x - 0.5 * WIN_WIDTH) / (0.5 * WIN_WIDTH * cam->dist)
		 + cam->offset.x;
	c.im = (y - 0.5 * WIN_HEIGHT) / (0.5 * WIN_HEIGHT * cam->dist)
		 + cam->offset.y;
	return (c);
}
