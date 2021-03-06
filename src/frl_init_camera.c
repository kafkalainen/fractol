/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_init_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:20:07 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/28 13:12:15 by jnivala          ###   ########.fr       */
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
	cam->colour.g = 16;
	cam->colour.b = 26;
	cam->mode = 4;
	cam->shape.re = -0.7;
	cam->shape.im = 0.27015;
	cam->max_iter = 30;
	cam->change = 0;
	cam->exit = 0;
	return (0);
}
