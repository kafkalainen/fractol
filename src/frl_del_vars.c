/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_del_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 09:21:44 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/08 12:33:53 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"
#include "../libft/libft.h"

char *frl_del_vars(t_vars **vars)
{
	if (*vars)
	{
		ft_memdel((void **)&((*vars)->data));
		ft_memdel((void **)&((*vars)));
	}
	return ("ERROR: Invalid file.");
}
