/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_init_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:20:07 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/01 15:14:35 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"

int frl_init_camera(t_cam *cur)
{
	cur->ang_x = 0.0;
	cur->ang_y = 0.0;
	cur->ang_z = 0.0;
	cur->dist = 0.0;
	cur->vector.x = 0.0;
	cur->vector.y = 0.0;
	cur->vector.z = 0.0;
	cur->colour = TURQUOISE;
	return (0);
}
