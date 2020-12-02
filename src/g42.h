/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 08:32:27 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/02 13:52:44 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G42_H
# define G42_H
# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define ENTERNOTIFY 7
# define LEAVENOTIFY 8
# define FOCUSIN 9
# define FOCUSOUT 10
# define KEYMAPNOTIFY 11
# define EXPOSE 12
# define GRAPHICSEXPOSE 13
# define NOEXPOSE 14
# define VISIBILITYNOTIFY 15
# define CREATENOTIFY 16
# define DESTROYNOTIFY 17
# define UNMAPNOTIFY 18
# define MAPNOTIFY 19
# define MAPREQUEST 20
# define REPARENTNOTIFY 21
# define CONFIGURENOTIFY 22
# define CONFIGUREREQUEST 23
# define GRAVITYNOTIFY 24
# define RESIZEREQUEST 25
# define CIRCULATENOTIFY 26
# define CIRCULATEREQUEST 27
# define PROPERTYNOTIFY 28
# define SELECTIONCLEAR 29
# define SELECTIONREQUEST 30
# define SELECTIONNOTIFY 31
# define COLORMAPNOTIFY 32
# define CLIENTMESSAGE 33
# define MAPPINGNOTIFY 34
# define GENERICEVENT 35
# define LASTEVENT 36
# define NOEVENTMASK 0L
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)
# define BUTTONPRESSMASK (1L<<2)
# define BUTTONRELEASEMASK (1L<<3)
# define ENTERWINDOWMASK (1L<<4)
# define LEAVEWINDOWMASK (1L<<5)
# define POINTERMOTIONMASK (1L<<6)
# define POINTERMOTIONHINTMASK (1L<<7)
# define BUTTON1MOTIONMASK (1L<<8)
# define BUTTON2MOTIONMASK (1L<<9)
# define BUTTON3MOTIONMASK (1L<<10)
# define BUTTON4MOTIONMASK (1L<<11)
# define BUTTON5MOTIONMASK (1L<<12)
# define BUTTONMOTIONMASK (1L<<13)
# define KEYMAPSTATEMASK (1L<<14)
# define EXPOSUREMASK (1L<<15)
# define VISIBILITYCHANGEMASK (1L<<16)
# define STRUCTURENOTIFYMASK (1L<<17)
# define RESIZEREDIRECTMASK (1L<<18)
# define SUBSTRUCTURENOTIFYMASK (1L<<19)
# define SUBSTRUCTUREREDIRECTMASK (1L<<20)
# define FOCUSCHANGEMASK (1L<<21)
# define PROPERTYCHANGEMASK (1L<<22)
# define COLORMAPCHANGEMASK (1L<<23)
# define OWNERGRABBUTTONMASK (1L<<24)
# define PI 3.14159265
# define LIGHTPINK 0xFFB6C1
# define PINK 0xFFC0CB
# define CRIMSON 0xDC143C
# define LAVENDERBLUSH 0xFFF0F5
# define PALEVIOLETRED 0xDB7093
# define HOTPINK 0xFF69B4
# define DEEPPINK 0xFF1493
# define MEDIUMVIOLETRED 0xC71585
# define ORCHID 0xDA70D6
# define THISTLE 0xD8BFD8
# define PLUM 0xDDA0DD
# define VIOLET 0xEE82EE
# define FUCHSIA 0xFF00FF
# define DARKMAGENTA 0x8B008B
# define PURPLE 0x800080
# define MEDIUMORCHID 0xBA55D3
# define DARKVIOLET 0x9400D3
# define DARKORCHID 0x9932CC
# define INDIGO 0x4B0082
# define BLUEVIOLET 0x8A2BE2
# define MEDIUMPURPLE 0x9370DB
# define MEDIUMSLATEBLUE 0x7B68EE
# define SLATEBLUE 0x6A5ACD
# define DARKSLATEBLUE 0x483D8B
# define GHOSTWHITE 0xF8F8FF
# define LAVENDER 0xE6E6FA
# define BLUE 0x0000FF
# define MEDIUMBLUE 0x0000CD
# define DARKBLUE 0x00008B
# define NAVY 0x000080
# define MIDNIGHTBLUE 0x191970
# define ROYALBLUE 0x4169E1
# define CORNFLOWERBLUE 0x6495ED
# define LIGHTSTEELBLUE 0xB0C4DE
# define LIGHTSLATEGRAY 0x778899
# define SLATEGRAY 0x708090
# define DODGERBLUE 0x1E90FF
# define ALICEBLUE 0xF0F8FF
# define STEELBLUE 0x4682B4
# define LIGHTSKYBLUE 0x87CEFA
# define SKYBLUE 0x87CEEB
# define DEEPSKYBLUE 0x00BFFF
# define LIGHTBLUE 0xADD8E6
# define POWDERBLUE 0xB0E0E6
# define CADETBLUE 0x5F9EA0
# define DARKTURQUOISE 0x00CED1
# define AZURE 0xF0FFFF
# define LIGHTCYAN 0xE0FFFF
# define PALETURQUOISE 0xAFEEEE
# define AQUA 0x00FFFF
# define DARKCYAN 0x008B8B
# define TEAL 0x008080
# define DARKSLATEGRAY 0x2F4F4F
# define MEDIUMTURQUOISE 0x48D1CC
# define LIGHTSEAGREEN 0x20B2AA
# define TURQUOISE 0x40E0D0
# define AQUAMARINE 0x7FFFD4
# define MEDIUMAQUAMARINE 0x66CDAA
# define MEDIUMSPRINGGREEN 0x00FA9A
# define MINTCREAM 0xF5FFFA
# define SPRINGGREEN 0x00FF7F
# define MEDIUMSEAGREEN 0x3CB371
# define SEAGREEN 0x2E8B57
# define HONEYDEW 0xF0FFF0
# define DARKSEAGREEN 0x8FBC8F
# define PALEGREEN 0x98FB98
# define LIGHTGREEN 0x90EE90
# define LIMEGREEN 0x32CD32
# define LIME 0x00FF00
# define FORESTGREEN 0x228B22
# define GREEN 0x008000
# define DARKGREEN 0x006400
# define LAWNGREEN 0x7CFC00
# define CHARTREUSE 0x7FFF00
# define GREENYELLOW 0xADFF2F
# define DARKOLIVEGREEN 0x556B2F
# define YELLOWGREEN 0x9ACD32
# define OLIVEDRAB 0x6B8E23
# define IVORY 0xFFFFF0
# define BEIGE 0xF5F5DC
# define LIGHTYELLOW 0xFFFFE0
# define LIGHTGOLDENRODYELLOW 0xFAFAD2
# define YELLOW 0xFFFF00
# define OLIVE 0x808000
# define DARKKHAKI 0xBDB76B
# define PALEGOLDENROD 0xEEE8AA
# define LEMONCHIFFON 0xFFFACD
# define KHAKI 0xF0E68C
# define GOLD 0xFFD700
# define CORNSILK 0xFFF8DC
# define GOLDENROD 0xDAA520
# define DARKGOLDENROD 0xB8860B
# define FLORALWHITE 0xFFFAF0
# define OLDLACE 0xFDF5E6
# define WHEAT 0xF5DEB3
# define ORANGE 0xFFA500
# define MOCCASIN 0xFFE4B5
# define PAPAYAWHIP 0xFFEFD5
# define BLANCHEDALMOND 0xFFEBCD
# define NAVAJOWHITE 0xFFDEAD
# define ANTIQUEWHITE 0xFAEBD7
# define TAN 0xD2B48C
# define BURLYWOOD 0xDEB887
# define DARKORANGE 0xFF8C00
# define BISQUE 0xFFE4C4
# define LINEN 0xFAF0E6
# define PERU 0xCD853F
# define PEACHPUFF 0xFFDAB9
# define SANDYBROWN 0xF4A460
# define CHOCOLATE 0xD2691E
# define SADDLEBROWN 0x8B4513
# define SEASHELL 0xFFF5EE
# define SIENNA 0xA0522D
# define LIGHTSALMON 0xFFA07A
# define CORAL 0xFF7F50
# define ORANGERED 0xFF4500
# define DARKSALMON 0xE9967A
# define TOMATO 0xFF6347
# define SALMON 0xFA8072
# define MISTYROSE 0xFFE4E1
# define LIGHTCORAL 0xF08080
# define SNOW 0xFFFAFA
# define ROSYBROWN 0xBC8F8F
# define INDIANRED 0xCD5C5C
# define RED 0xFF0000
# define BROWN 0xA52A2A
# define FIREBRICK 0xB22222
# define DARKRED 0x8B0000
# define MAROON 0x800000
# define WHITE 0xFFFFFF
# define WHITESMOKE 0xF5F5F5
# define GAINSBORO 0xDCDCDC
# define LIGHTGREY 0xD3D3D3
# define SILVER 0xC0C0C0
# define DARKGRAY 0xA9A9A9
# define GRAY 0x808080
# define DIMGRAY 0x696969
# define BLACK 0x000000

# include <string.h>

typedef struct	s_counter {
	size_t	i;
	size_t	j;
	size_t	k;
}				t_counter;

typedef struct	s_m4x4 {
	double	m[4][4];
}				t_m4x4;

typedef struct	s_m3x3 {
	double	m[3][3];
}				t_m3x3;

typedef struct	s_pxl_c
{
	int			c[36];
}				t_pxl_c;

typedef struct	s_uv {
	int			u;
	int			v;
	double		s_scale;
}				t_uv;

typedef struct	s_vec3 {
	double		x;
	double		y;
	double		z;
	double		c_scale;
}				t_vec3;

typedef struct	s_camera
{
	double		ang_x;
	double		ang_y;
	double		ang_z;
	double		dist;
	t_vec3		vector;
	int			colour;
}				t_cam;

typedef struct	s_map {
	t_vec3		*coord;
	t_vec3		*proj;
	t_uv		*screen;
	size_t		height;
	double		max_depth;
	double		min_depth;
	size_t		*width;
	size_t		max_width;
	size_t		pts;
}				t_map;

typedef struct	s_colour {
	int			t;
	int			r;
	int			g;
	int			b;
}				t_colour;

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bpp;
	int			llen;
	int			endian;
	int			text_size;
}				t_data;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_data		*data;
	t_map		*map;
	t_cam		cur;
}				t_vars;

int				g42_create_trgb(int t, int r, int g, int b);

int				g42_c_grad(t_uv p0, t_uv p1, t_uv s, int colour);

int				g42_get_transparency(int trgb);

int				g42_get_red(int trgb);

int				g42_get_green(int trgb);

int				g42_get_blue(int trgb);

int				g42_invert_trgb(int t, int r, int g, int b);

void			g42_mlx_pixel_put(t_data *data, int x, int y, int color);

void			g42_solid_square(t_data *data, t_uv offset, int c, int s);

void			g42_mlx_draw_line_dda(t_data *data, t_uv p0, t_uv p1, int c);

void			g42_draw_line_bre(t_data *data, t_uv p0, t_uv p1, int c);

void			g42_mlx_draw_x_y_line(t_data *data, t_uv p0, t_uv p1, int c);

void			g42_mlx_draw_diagonal(t_data *data, t_uv p0, t_uv p1, int c);

void			g42_normalize_vector(t_vec3 *v);

int				g42_dot_product(t_vec3 *a, t_vec3 *b);

void			g42_cross_product(t_vec3 *a, t_vec3 *b, t_vec3 *cross);

t_vec3			g42_multi_vec_matrix(const t_vec3 *src, t_m4x4 *x);

void			g42_rotate_x_axis(t_vec3 *vec, double angle);

void			g42_rotate_y_axis(t_vec3 *vec, double angle);

void			g42_rotate_z_axis(t_vec3 *vec, double angle);

void			g42_scale_point(t_vec3 *vec, double scale);

void			g42_scale_y(t_vec3 *vec, double scale);

void			g42_translate(t_vec3 *vec, t_vec3 a);

void			g42_clip_point(t_vec3 *a);

t_uv			g42_2d_to_uv(t_vec3 coord, t_map *map, t_cam *cam);

t_uv			g42_ndc_to_raster_space(t_vec3 ndc);

void			g42_mod_pts(t_map *map, void (*f)(t_vec3*, double), double mod);

void			g42_mod_vec(t_map *map, void (*f)(t_vec3*, t_vec3), t_vec3 mod);

void			g42_str_pxl(t_data *data, t_uv coord, char *str);

t_pxl_c			g42_pxl_alphabet(int l, int b, int c);

t_pxl_c			g42_pxl_numbers(int l, int b, int c);

t_colour		g42_hex_to_trgb(int trgb);

int				g42_trgb_to_hex(t_colour trgb);

double			g42_lerp(double v0, double v1, double t);
#endif
