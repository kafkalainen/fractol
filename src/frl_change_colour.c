/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_change_colour.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 09:33:31 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/02 13:19:23 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"
#include "frl.h"
#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"

static int frl_return_next_colour(int colour)
{
	int i;
	static int tab[] = {
		HOTPINK, PALETURQUOISE, PALEGREEN, LIMEGREEN,
		LIGHTBLUE, POWDERBLUE, LIGHTYELLOW, SANDYBROWN,
		SNOW, ORANGE, TURQUOISE, LIGHTPINK, MISTYROSE };

	i = 0;
	while (i < 14)
	{
		if (i + 1 < 13 && tab[i] == colour)
			return (tab[i + 1]);
		if (i + 1 == 13 && tab[i] == colour)
			return (tab[0]);
		i++;
	}
	return (colour);
}

int frl_change_colour(int keycode, t_vars *vars)
{
	keycode = keycode;
	mlx_destroy_image(vars->mlx, vars->data->img);
	vars->data->img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->data->addr = mlx_get_data_addr(vars->data->img, &vars->data->bpp,
										 &vars->data->llen, &vars->data->endian);
	vars->cur.colour = frl_return_next_colour(vars->cur.colour);
	//frl_draw_wire(vars->data, vars->map, vars->map->screen, vars->cur.colour);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
	return (0);
}
