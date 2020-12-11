/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_linear_mapping.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 09:05:04 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/10 09:18:54 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

double	g42_linear_mapping(double val, t_bound x1, t_bound x2)
{
	return (((val - x1.lower) / (x1.upper - x1.lower))
			* (x2.upper - x2.lower) + x2.lower);
}
