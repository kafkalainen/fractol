/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_paint_current_fractal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:47:50 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/16 16:38:53 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "../libft/libft.h"
#include <pthread.h>
#include <stdlib.h>

static void	*frl_paint_area(void *args)
{
	t_uv		screen;
	t_arg		*arg;
	pthread_t	current;
	int			index;
	int			limit;

	arg = (t_arg*)args;
	index = 0;
	current = pthread_self();
	while (current != arg->tid[index])
		index++;
	screen.v = index * WIN_H / MAX_THREADS + MENU_HEIGHT;
	limit = (index + 1) * WIN_H / MAX_THREADS  + MENU_HEIGHT;
	while (screen.v < limit)
	{
		screen.u = 0;
		while (screen.u < WIN_W)
		{
			arg->f(arg->data, screen, arg->cam);
			screen.u++;
		}
		screen.v++;
	}
	return (NULL);
}

void		frl_paint_current_fractal(t_data *data, t_cam *cam, \
void (*f)(t_data*, t_uv, t_cam*))
{
	t_arg		args;
	int			i;

	args.tid = (pthread_t*)malloc(sizeof(pthread_t) * MAX_THREADS);
	args.cam = cam;
	args.data = data;
	args.f = f;
	i = 0;
	while (i < MAX_THREADS)
	{
		pthread_create(&args.tid[i], NULL, &frl_paint_area, (void*)&args);
		i++;
	}
	while (i--)
		pthread_join(args.tid[i], NULL);
	ft_memdel((void**)&args.tid);
}
