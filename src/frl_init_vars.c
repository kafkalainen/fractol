/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_init_vars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:39:39 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/16 15:01:46 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"
#include <stdlib.h>

t_vars	**frl_init_vars(int argc)
{
	int		i;
	t_vars	**vars;

	i = 1;
	if (!(vars = (t_vars**)malloc(sizeof(t_vars*) * argc + 1)))
		return (NULL);
	while (i < argc)
	{
		if (!(vars[i] = (t_vars*)malloc(sizeof(t_vars))))
			return (NULL);
		if (!(vars[i]->data = (t_data*)malloc(sizeof(t_data))))
			return (NULL);
		vars[i]->index = i;
		i++;
	}
	return (vars);
}
