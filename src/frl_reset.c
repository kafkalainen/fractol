/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:35:51 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/27 15:21:12 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "frl.h"

int		frl_reset(int buttoncode, t_vars *vars)
{
	if (buttoncode == KEY_4)
	{
		frl_init_camera(&vars->cur);
		vars->cur.change = 1;
		if (ft_strequ(vars->set, "thorn"))
		{
			vars->cur.shape.re = 0.102;
			vars->cur.shape.im = -0.04;
		}
		if (ft_strequ(vars->set, "biomorph"))
		{
			vars->cur.shape.re = 0.5;
			vars->cur.shape.im = 0.0;
		}
	}
	return (0);
}
