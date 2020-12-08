/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_handle_buttonpress.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:37:44 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/08 18:32:17 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"

int	frl_handle_buttonpress(int buttoncode, int x, int y, t_vars *vars)
{
	if (x && y && vars && (buttoncode == ZOOM_OUT || buttoncode == ZOOM_IN))
		frl_zoom_fractal(buttoncode, vars);
	return (0);
}
