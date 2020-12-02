/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_draw_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:53:34 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/02 12:40:02 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"

int frl_draw_menu(t_data *data, int colour)
{
	t_uv pixel;
	t_uv instructions;
	t_uv title;

	instructions.u = 20;
	instructions.v = 40;
	title.u = WIN_WIDTH / 2 - 75;
	title.v = MENU_HEIGHT / 2 - 35;
	pixel.v = 0;
	while (pixel.v < MENU_HEIGHT)
	{
		pixel.u = 0;
		while (pixel.u < WIN_WIDTH)
		{
			g42_mlx_pixel_put(data, pixel.u, pixel.v, colour);
			pixel.u++;
		}
		pixel.v++;
	}
	frl_draw_instructions_left(data, instructions);
	instructions.u = (int)(WIN_WIDTH / 4 * 3);
	instructions.v = 40;
	frl_draw_instructions_right(data, instructions);
	frl_draw_title(data, title);
	return (0);
}
