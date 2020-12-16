/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_mutate_iterations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:06:14 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/16 15:21:18 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../mlx_linux/mlx.h"
#include <stdlib.h>
#include "../libft/libft.h"

int		frl_mutate_iterations(int buttoncode, t_vars *vars)
{
	if (buttoncode == KEY_Q)
	{
		if (vars->cur.max_iter > 10)
			vars->cur.max_iter -= 10;
	}
	if (buttoncode == KEY_E)
	{
		if (vars->cur.max_iter < 1000)
			vars->cur.max_iter += 10;
	}
	vars->cur.change = 1;
	return (0);
}
