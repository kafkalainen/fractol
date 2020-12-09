/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_cabs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 10:26:31 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/09 10:30:50 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "g42.h"

double	g42_cabs(t_complex c)
{
	return (sqrt((c.re * c.re) + (c.im * c.im)));
}
