/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_draw_title.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:42:54 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/01 15:15:51 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

void frl_draw_title(t_data *data, t_uv coord)
{
	data->text_size = 10;
	g42_str_pxl(data, coord, "Fract'ol");
}
