/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_mlx_pixel_put.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 09:07:04 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 13:10:12 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"
#include "frl.h"

void	g42_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	if (x > 0 && y > 0 && x <= WIN_W && y <= WIN_H)
	{
		dst = data->addr + (y * data->llen + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}
