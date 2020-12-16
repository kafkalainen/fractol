/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_init_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:20:07 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/16 11:59:29 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include <stdlib.h>

int		frl_init_camera(t_cam *cam)
{
	cam->dist = 1.0;
	cam->offset.x = 0.0;
	cam->offset.y = 0.0;
	cam->colour.r = 16;
	cam->colour.g = 52;
	cam->colour.b = 166;
	cam->mode = 4;
	cam->shape.re = -0.7;
	cam->shape.im = 0.27015;
	cam->max_iter = 30;
	cam->change = 0;
	cam->move_change = 0;
	cam->mode_change = 0;
	cam->colour_change = 0;
	cam->shape_change = 0;
	cam->zoom_change = 0;
	cam->reset_change = 0;
	cam->reset_colour = 0;
	cam->iter_change = 0;
	cam->exit = 0;
	return (0);
}
