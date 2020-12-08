/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_get_colours.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:03:43 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/04 13:02:06 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"
#include "../libft/libft.h"

static t_colour_arr		get_colours(void)
{
	return ((t_colour_arr){{
		lightpink, pink, crimson, lavenderblush, palevioletred, hotpink,
		deeppink, mediumvioletred, orchid, thistle, plum, violet, fuchsia,
		darkmagenta, purple, mediumorchid, darkviolet, darkorchid, indigo,
		blueviolet, mediumpurple, mediumslateblue, slateblue, darkslateblue,
		ghostwhite, lavender, blue, mediumblue, darkblue, navy, midnightblue,
		royalblue, cornflowerblue, lightsteelblue, lightslategray, slategray,
		dodgerblue, aliceblue, steelblue, lightskyblue, skyblue, deepskyblue,
		lightblue, powderblue, cadetblue, darkturquoise, azure, lightcyan,
		paleturquoise, aqua, darkcyan, teal, darkslategray, mediumturquoise,
		lightseagreen, turquoise, aquamarine, mediumaquamarine,
		mediumspringgreen, mintcream, springgreen, mediumseagreen, seagreen,
		honeydew, darkseagreen, palegreen, lightgreen, limegreen, lime,
		forestgreen, green, darkgreen, lawngreen, chartreuse, greenyellow,
		darkolivegreen, yellowgreen, olivedrab, ivory, beige, lightyellow,
		lightgoldenrodyellow, yellow, olive, darkkhaki, palegoldenrod,
		lemonchiffon, khaki, gold, cornsilk, goldenrod, darkgoldenrod,
		floralwhite, oldlace, wheat, orange, moccasin, papayawhip,
		blanchedalmond, navajowhite, antiquewhite, c_tan, burlywood,
		darkorange, bisque, linen, peru, peachpuff, sandybrown, chocolate,
		saddlebrown, seashell, sienna, lightsalmon, coral, orangered,
		darksalmon, tomato, salmon, mistyrose, lightcoral, snow, rosybrown,
		indianred, red, brown, firebrick, darkred, maroon, white, whitesmoke,
		gainsboro, lightgrey, silver, darkgray, gray, dimgray
	}});
}

int						g42_get_colours(int index)
{
	t_colour_arr	colours;

	colours = get_colours();
	return (colours.colour[index % 137]);
}
