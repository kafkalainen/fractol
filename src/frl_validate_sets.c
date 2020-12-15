/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_validate_sets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 10:54:04 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 13:33:15 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../libft/libft.h"

int				frl_validate_sets(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "julia") != 0 &&
			ft_strcmp(argv[i], "mandelbrot") != 0 &&
			ft_strcmp(argv[i], "burningship") != 0)
		{
			ft_putstr_fd("ERROR: Given parameter is not valid set\n", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putchar_fd('\n', 2);
			frl_usage();
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
