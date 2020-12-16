/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:10:09 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/16 15:39:30 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include <stdlib.h>
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"

t_vars		*frl_clean(t_vars **vars)
{
	mlx_loop_hook((*vars)->mlx, frl_image_loop, NULL);
	*(*vars)->window_count = *(*vars)->window_count - 1;
	mlx_destroy_image((*vars)->mlx, (*vars)->data->img);
	mlx_destroy_window((*vars)->mlx, (*vars)->win);
	(*vars)->win = NULL;
	ft_memdel((void**)&(*vars)->set);
	ft_memdel((void**)&(*vars)->data);
	if (*(*vars)->window_count == 0)
	{
		mlx_destroy_display((*vars)->mlx);
		ft_memdel((void**)&(*vars)->mlx);
		free((*vars)->arr);
		ft_memdel((void**)&(*vars));
		exit(EXIT_SUCCESS);
	}
	ft_memdel((void**)&(*vars));
	return (NULL);
}
