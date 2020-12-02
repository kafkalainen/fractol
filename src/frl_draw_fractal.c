/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_draw_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:53:34 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/02 14:03:55 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"

void	frl_draw_fractal(t_data *data, int colour)
{
	//frl_draw_background(data);
	frl_smooth_colouring(data);
	frl_draw_menu(data, colour);
}
