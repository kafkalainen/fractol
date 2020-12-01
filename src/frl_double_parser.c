/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_double_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:07:10 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/01 15:14:35 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

double frl_double_parser(int begin, int end)
{
	int len;
	double db;

	db = (double)end;
	len = ft_nb_len(end, 10);
	while (len)
	{
		db = (double)db * 0.1;
		len--;
	}
	db += (double)begin;
	return (db);
}
