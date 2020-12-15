/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_init_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 08:43:07 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 10:01:14 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"

int		frl_init_windows(t_vars **vars, int *windows, char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		vars[i]->arr = (void**)vars;
		vars[i]->mlx = vars[1]->mlx;
		vars[i]->window_count = windows;
		if (!(vars[i]->win = mlx_new_window(vars[i]->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol")))
			return (EXIT_FAILURE);
		vars[i]->data->img = mlx_new_image(vars[i]->mlx, WIN_WIDTH, WIN_HEIGHT);
		vars[i]->data->addr = mlx_get_data_addr(vars[i]->data->img,
			&vars[i]->data->bpp, &vars[i]->data->llen, &vars[i]->data->endian);
		frl_init_camera(&vars[i]->cur);
		vars[i]->set = ft_strdup(argv[i]);
		if (frl_draw_fractal(&vars[i]->cur, vars[i]->data, vars[i]->set))
			return (EXIT_FAILURE);
		mlx_put_image_to_window(vars[i]->mlx, vars[i]->win, vars[i]->data->img, 0, 0);
		mlx_hook(vars[i]->win, KEYPRESS, KEYPRESSMASK, frl_handle_keypress, vars[i]);
		mlx_hook(vars[i]->win, BUTTONPRESS, BUTTONPRESSMASK, frl_handle_buttonpress, vars[i]);
		mlx_hook(vars[i]->win, MOTIONNOTIFY, POINTERMOTIONMASK, frl_handle_movement, vars[i]);
		i++;
	}
	return (0);
}
