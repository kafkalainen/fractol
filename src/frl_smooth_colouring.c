/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_smooth_colouring.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:47:50 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/02 14:02:30 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frl.h"
#include "math.h"

static int		frl_colours(int index) {
	static int tab[] = {
		PINK, CRIMSON, LAVENDERBLUSH, PALEVIOLETRED, HOTPINK,
		DEEPPINK, MEDIUMVIOLETRED, ORCHID, THISTLE, PLUM, VIOLET, FUCHSIA,
		DARKMAGENTA, PURPLE, MEDIUMORCHID, DARKVIOLET, DARKORCHID, INDIGO,
		BLUEVIOLET, MEDIUMSLATEBLUE, SLATEBLUE, DARKSLATEBLUE, GHOSTWHITE,
		LAVENDER, BLUE, MEDIUMBLUE, DARKBLUE, NAVY, MIDNIGHTBLUE,
		ROYALBLUE, LIGHTSTEELBLUE, LIGHTSLATEGRAY, SLATEGRAY, DODGERBLUE,
		ALICEBLUE, STEELBLUE, LIGHTSKYBLUE, SKYBLUE, DEEPSKYBLUE, LIGHTBLUE,
		POWDERBLUE, CADETBLUE, DARKTURQUOISE, AZURE, LIGHTCYAN, PALETURQUOISE,
		AQUA, DARKCYAN, TEAL, DARKSLATEGRAY, LIGHTSEAGREEN, TURQUOISE,
		AQUAMARINE, MEDIUMAQUAMARINE, MINTCREAM, MINTCREAM, SPRINGGREEN,
		MEDIUMSEAGREEN, SEAGREEN, HONEYDEW, LIGHTGREEN, LIME, FORESTGREEN,
		GREEN, DARKGREEN, LAWNGREEN, CHARTREUSE, GREENYELLOW, DARKOLIVEGREEN,
		YELLOWGREEN, OLIVEDRAB, IVORY, BEIGE, LIGHTYELLOW, LIGHTGOLDENRODYELLOW,
		YELLOW, OLIVE, DARKKHAKI, PALEGOLDENROD, LEMONCHIFFON, KHAKI, GOLD, CORNSILK,
		GOLDENROD, DARKGOLDENROD, FLORALWHITE, OLDLACE, WHEAT, ORANGE, MOCCASIN,
		PAPAYAWHIP, BLANCHEDALMOND, NAVAJOWHITE, ANTIQUEWHITE, TAN, BURLYWOOD,
		DARKORANGE, BISQUE, LINEN, PERU, PEACHPUFF, SANDYBROWN, CHOCOLATE, SADDLEBROWN,
		SEASHELL, SIENNA, LIGHTSALMON, CORAL, ORANGERED, DARKSALMON, TOMATO, SALMON,
		MISTYROSE, LIGHTCORAL, SNOW, ROSYBROWN, INDIANRED, RED, BROWN, FIREBRICK, DARKRED,
		MAROON, WHITE, WHITESMOKE, GAINSBORO, LIGHTGREY, SILVER, DARKGRAY, GRAY, DIMGRAY
	};
	if (index <= 1000) {
		index = index % 129;
		return (tab[index]);
	}
	return (tab[0]);
}

static void		frl_draw_pxl(t_data *data, t_uv screen)
{
	t_vec3	re;
	t_vec3	cur;
	int		i;
	double	x_new;
	double	log_zn;
	double	nu;

	re.x = (screen.u - WIN_WIDTH / 2.0) * 4.0 / WIN_WIDTH;
	re.y = (screen.v - WIN_HEIGHT / 2.0) * 4.0 / WIN_WIDTH;
	i = 0;
	cur.x = 0;
	cur.y = 0;
	while (cur.x * cur.x + cur.y * cur.y <= 4 && i < 1000)
	{
		x_new = cur.x * cur.x - cur.y * cur.y + re.x;
		cur.y = 2 * cur.x * cur.y + re.y;
		cur.x = x_new;
		i++;
	}
	if (i < 1000)
	{
		log_zn = log(cur.x*cur.x + cur.y*cur.y) / 2;
		nu = log(log_zn / log(2)) / log(2);
		i = i + 1 - nu;
		int colour1 = frl_colours(i);
		int colour2 = frl_colours(i + 1);
		colour1 = g42_lerp(colour1, colour2, i % 1);
		g42_mlx_pixel_put(data, screen.u, screen.v, colour1);
	}
	else
		g42_mlx_pixel_put(data, screen.u, screen.v, BLACK);
}

void			frl_smooth_colouring(t_data *data)
{
	t_uv	screen;

	screen.v = 0;
	screen.u = 0;
	while (screen.v < WIN_HEIGHT)
	{
		screen.u = 0;
		while (screen.u < WIN_WIDTH)
		{
			frl_draw_pxl(data, screen);
			screen.u++;
		}
		screen.v++;
	}
}
