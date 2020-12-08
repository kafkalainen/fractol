/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_init_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:20:07 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/04 13:04:42 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include <stdlib.h>

int		frl_init_camera(t_cam *cur)
{
	cur->ang_x = 0.0;
	cur->ang_y = 0.0;
	cur->ang_z = 0.0;
	cur->dist = 1.0;
	cur->offset.u = 0.0;
	cur->offset.v = 0.0;
	cur->colour = gray;
	return (0);
}
