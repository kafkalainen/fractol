/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_normalize_coordinates.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 09:43:01 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/16 17:17:19 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"

t_complex	frl_normalize_coordinates(int x, int y, t_cam *cam)
{
	t_complex	c;

	c.re = 2.0 * (x - 0.5 * WIN_W) / (0.5 * WIN_W * cam->dist)
		+ cam->offset.x;
	c.im = 1.5 * ((y - MENU_HEIGHT) - 0.5 * (WIN_H - MENU_HEIGHT)) /
	(0.5 * (WIN_H - MENU_HEIGHT) * cam->dist) + cam->offset.y;
	return (c);
}
