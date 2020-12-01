/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_draw_wire.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 09:20:19 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/01 15:14:35 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"

void frl_draw_wire(t_data *data, t_map *map, t_uv *coord, int colour)
{
	size_t x;
	size_t z;
	t_uv res;

	z = 0;
	frl_draw_background(data);
	while (z < map->height)
	{
		x = 0;
		while (x < map->width[z])
		{
			res = coord[frl_idx(x, z, map)];
			if (z < map->height - 1 && x < map->width[z + 1])
				frl_draw_line(data, res, coord[frl_idx(x, z + 1, map)], colour);
			if (x < map->width[z] - 1)
				frl_draw_line(data, res, coord[frl_idx(x + 1, z, map)], colour);
			x++;
		}
		z++;
	}
	frl_draw_menu(data, colour);
}
