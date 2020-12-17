/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:35:51 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/17 12:12:47 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"

int		frl_reset(int buttoncode, t_vars *vars)
{
	if (buttoncode == KEY_4)
	{
		frl_init_camera(&vars->cur);
		vars->cur.change = 1;
	}
	return (0);
}
