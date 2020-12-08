/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_draw_instructions_right.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 07:01:40 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/03 18:15:56 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

void frl_draw_instructions_right(t_data *data, t_uv coord)
{
	g42_str_pxl(data, coord, "To switch views:");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Press 3 to increase y axis and 4 to flatten");
	coord.v += 7 * 2;
}
