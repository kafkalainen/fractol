/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_init_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:20:07 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 10:23:38 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include <stdlib.h>

int		frl_init_camera(t_cam *cur)
{
	cur->dist = 1.0;
	cur->offset.x = 0.0;
	cur->offset.y = 0.0;
	cur->colour.r = 16;
	cur->colour.g = 52;
	cur->colour.b = 166;
	cur->mode = 1;
	cur->shape.re = -0.7;
	cur->shape.im = 0.27015;
	return (0);
}
