/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_usage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:21:14 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 13:01:09 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"

int		frl_usage(void)
{
	ft_putendl_fd("Please provide a valid set. ./fractol <fractalname>", 1);
	ft_putendl_fd("These are:", 1);
	ft_putendl_fd("julia", 1);
	ft_putendl_fd("mandelbrot", 1);
	ft_putendl_fd("burningship", 1);
	ft_putendl_fd("You can also write multiple ones ie. julia mandelbrot", 1);
	return (EXIT_SUCCESS);
}
