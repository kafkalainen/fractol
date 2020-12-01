/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_rotate_y_axis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:21:37 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/30 18:40:22 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"
#include "math.h"

void	g42_rotate_y_axis(t_vec3 *vec, double angle)
{
	t_m4x4	m;
	double	c;
	double	s;

	c = cos(angle * (PI / 180));
	s = sin(angle * (PI / 180));
	m = (t_m4x4)
	{{
		{ c, 0, -s, 0},
		{ 0, 1, 0, 0},
		{ s, 0, c, 0},
		{ 0, 0, 0, 1},
	}};
	*vec = g42_multi_vec_matrix(vec, &m);
}
