/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_init_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:20:07 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/08 14:46:43 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include <stdlib.h>

int		frl_init_camera(t_cam *cur)
{
	cur->old_time = 0.0;
	cur->frame = 0.0;
	cur->time = 0.0;
	cur->dist = 1.0;
	cur->offset.x = 0.0;
	cur->offset.y = 0.0;
	cur->colour = gray;
	return (0);
}
