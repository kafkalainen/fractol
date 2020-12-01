/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_translate_coordinates.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 09:26:34 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/01 15:24:31 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include <stdlib.h>

t_uv *frl_translate_coordinates(t_map *map, t_cam *cam)
{
	size_t i;

	i = 0;
	if (map == NULL)
		return (NULL);
	while (i < map->pts)
	{
		map->screen[i] = g42_2d_to_uv(map->proj[i], map, cam);
		i++;
	}
	return (map->screen);
}
