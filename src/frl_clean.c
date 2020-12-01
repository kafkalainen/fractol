/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:10:09 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/01 15:14:35 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "g42.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"

t_vars *frl_clean(t_vars **vars)
{
	mlx_destroy_image((*vars)->mlx, (*vars)->data->img);
	mlx_destroy_window((*vars)->mlx, (*vars)->win);
	mlx_destroy_display((*vars)->mlx);
	ft_memdel((void **)&(*vars)->map->coord);
	ft_memdel((void **)&(*vars)->map->proj);
	ft_memdel((void **)&(*vars)->map->screen);
	ft_memdel((void **)&(*vars)->map->width);
	ft_memdel((void **)&(*vars)->map);
	ft_memdel((void **)&(*vars)->data);
	ft_memdel((void **)&(*vars)->mlx);
	ft_memdel((void **)&(*vars));
	return (NULL);
}
