/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:47:56 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/11 08:15:27 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"
#include "g42.h"
#include "frl.h"
#include "stdio.h"

int		main(int argc, char **argv)
{
	t_vars	**vars;
	int		i;
	int		open_windows;

	i = 1;
	open_windows = argc - 1;
	if (argc == 1)
		return (frl_error("Please provide a valid Fractalset. ./fractol <fractalname>"));
	if (!(vars = frl_init_vars(argc)))
		return (EXIT_FAILURE);
	if (!(vars[1]->mlx = mlx_init()))
		return (EXIT_FAILURE);
	while (i < argc)
	{
		vars[i]->arr = (void**)vars;
		vars[i]->mlx = vars[1]->mlx;
		vars[i]->window_count = &open_windows;
		if (!(vars[i]->win = mlx_new_window(vars[1]->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol")))
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
		i++;
	}
	mlx_loop(vars[1]->mlx);
	return (EXIT_SUCCESS);
}
