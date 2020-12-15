/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_draw_instructions_left.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:18:09 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 21:46:36 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

void	frl_draw_instructions_left(t_data *data, t_uv coord)
{
	data->text_size = 2;
	g42_str_pxl(data, coord, "Press arrow keys to move around");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Use mouse wheel to zoom");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Use mouse to mutate Julia set");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Use keys Q and E to mutate number of iterations");
	coord.v += 7 * 2;
}
