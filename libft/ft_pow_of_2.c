/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_of_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 09:52:47 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/30 10:40:24 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow_of_2(double base, double exponent)
{
	if (exponent == 0.0 || base == 0.0)
		return (1);
	return (base * base);
}
