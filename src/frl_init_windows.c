/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_init_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 08:43:07 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 20:35:20 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"

int		frl_init_windows(t_vars **v, int *windows, char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		v[i]->arr = (void**)v;
		v[i]->mlx = v[1]->mlx;
		v[i]->window_count = windows;
		if (!(v[i]->win = mlx_new_window(v[i]->mlx, WIN_W, WIN_H, argv[i])))
			return (EXIT_FAILURE);
		v[i]->data->img = mlx_new_image(v[i]->mlx, WIN_W, WIN_H);
		v[i]->data->addr = mlx_get_data_addr(v[i]->data->img,
			&v[i]->data->bpp, &v[i]->data->llen, &v[i]->data->endian);
		frl_init_camera(&v[i]->cur);
		v[i]->set = ft_strdup(argv[i]);
		if (frl_draw_fractal(&v[i]->cur, v[i]->data, v[i]->set))
			return (EXIT_FAILURE);
		mlx_put_image_to_window(v[i]->mlx, v[i]->win,
			v[i]->data->img, 0, 0);
		mlx_hook(v[i]->win, KEYPRESS, KEYPRESSMASK, frl_handle_key, v[i]);
		mlx_hook(v[i]->win, BTNPRESS, BTNPRESSMASK, frl_handle_btn, v[i]);
		mlx_hook(v[i]->win, MTNNOTIFY, PTRMTNMASK, frl_handle_mov, v[i]);
		// mlx_loop_hook(v[i]->mlx, frl_image_loop, v[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
