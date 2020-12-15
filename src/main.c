/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:47:56 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/11 08:57:53 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "frl.h"

int		main(int argc, char **argv)
{
	t_vars	**vars;
	int		windows;

	windows = argc - 1;
	if (argc == 1)
		return (frl_error("Please provide a valid Fractalset. ./fractol <fractalname>"));
	if (!(vars = frl_init_vars(argc)))
		return (EXIT_FAILURE);
	if (!(vars[1]->mlx = mlx_init()))
		return (EXIT_FAILURE);
	if (frl_init_windows(vars, &windows, argv, argc))
		return (EXIT_FAILURE);
	mlx_loop(vars[1]->mlx);
	return (EXIT_SUCCESS);
}
