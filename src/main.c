/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:47:56 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/02 12:12:46 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"
#include "g42.h"
#include "frl.h"
#include "stdio.h"

int main(int argc, char **argv)
{
	t_vars *vars;

	if (argc != 2)
		return (frl_error("Please provide a valid Fractalset. ./fractol <fractalname>"));
	if (!(vars = frl_init_vars()))
		return (EXIT_FAILURE);
	printf("%s\n", argv[1]);
	//if (frl_file_reader(vars->map, argv[1]))
	//	return (frl_error(frl_del_vars(&vars)));
	if (!(vars->mlx = mlx_init()))
		return (EXIT_FAILURE);
	if (!(vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol")))
		return (EXIT_FAILURE);
	vars->data->img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->data->addr = mlx_get_data_addr(vars->data->img,
										 &vars->data->bpp, &vars->data->llen, &vars->data->endian);
	frl_init_camera(&vars->cur);
	frl_draw_fractal(vars->data, vars->cur.colour);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
	mlx_hook(vars->win, KEYPRESS, KEYPRESSMASK, frl_handle_keypress, vars);
	mlx_loop(vars->mlx);
	return (EXIT_SUCCESS);
}
