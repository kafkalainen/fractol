/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_reset_colour.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:12:01 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/17 09:57:01 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"

int		frl_reset_colour(int buttoncode, t_vars *vars)
{
	if (buttoncode == KEY_3)
	{
		vars->cur.change = 1;
		vars->cur.colour.r = 16;
		vars->cur.colour.g = 52;
		vars->cur.colour.b = 16;
	}
	return (0);
}
