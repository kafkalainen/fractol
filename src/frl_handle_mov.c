/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_handle_mov.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:59:38 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/27 15:20:19 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"

int		frl_handle_mov(int x, int y, t_vars *vars)
{
	if (vars && x && y && (
		ft_strequ(vars->set, "julia") ||
		ft_strequ(vars->set, "thorn") ||
		ft_strequ(vars->set, "biomorph")))
	{
		vars->cur.change = 1;
		vars->cur.shape = frl_normalize_coordinates(x, y, &vars->cur);
	}
	return (0);
}
