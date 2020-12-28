/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_draw_instructions_right.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 07:01:40 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/27 15:22:52 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

void	frl_draw_instructions_right(t_data *data, t_uv coord)
{
	g42_str_pxl(data, coord, "Press 1 to change colour mode");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Press 2 to change colour");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Press 3 to reset colour");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Press 4 to reset all");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Press W to switch to constant");
	coord.v += 7 * 2;
}
