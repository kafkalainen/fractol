/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 08:32:27 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/09 11:54:16 by jnivala          ###   ########.fr       */
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
# include <string.h>
# include <pthread.h>

enum	e_colour {
	lightpink = 0xffb6c1,
	pink = 0xffc0cb,
	crimson = 0xdc143c,
	lavenderblush = 0xfff0f5,
	palevioletred = 0xdb7093,
	hotpink = 0xff69b4,
	deeppink = 0xff1493,
	mediumvioletred = 0xc71585,
	orchid = 0xda70d6,
	thistle = 0xd8bfd8,
	plum = 0xdda0dd,
	violet = 0xee82ee,
	fuchsia = 0xff00ff,
	darkmagenta = 0x8b008b,
	purple = 0x800080,
	mediumorchid = 0xba55d3,
	darkviolet = 0x9400d3,
	darkorchid = 0x9932cc,
	indigo = 0x4b0082,
	blueviolet = 0x8a2be2,
	mediumpurple = 0x9370db,
	mediumslateblue = 0x7b68ee,
	slateblue = 0x6a5acd,
	darkslateblue = 0x483d8b,
	ghostwhite = 0xf8f8ff,
	lavender = 0xe6e6fa,
	blue = 0x0000ff,
	mediumblue = 0x0000cd,
	darkblue = 0x00008b,
	navy = 0x000080,
	midnightblue = 0x191970,
	royalblue = 0x4169e1,
	cornflowerblue = 0x6495ed,
	lightsteelblue = 0xb0c4de,
	lightslategray = 0x778899,
	slategray = 0x708090,
	dodgerblue = 0x1e90ff,
	aliceblue = 0xf0f8ff,
	steelblue = 0x4682b4,
	lightskyblue = 0x87cefa,
	skyblue = 0x87ceeb,
	deepskyblue = 0x00bfff,
	lightblue = 0xadd8e6,
	powderblue = 0xb0e0e6,
	cadetblue = 0x5f9ea0,
	darkturquoise = 0x00ced1,
	azure = 0xf0ffff,
	lightcyan = 0xe0ffff,
	paleturquoise = 0xafeeee,
	aqua = 0x00ffff,
	darkcyan = 0x008b8b,
	teal = 0x008080,
	darkslategray = 0x2f4f4f,
	mediumturquoise = 0x48d1cc,
	lightseagreen = 0x20b2aa,
	turquoise = 0x40e0d0,
	aquamarine = 0x7fffd4,
	mediumaquamarine = 0x66cdaa,
	mediumspringgreen = 0x00fa9a,
	mintcream = 0xf5fffa,
	springgreen = 0x00ff7f,
	mediumseagreen = 0x3cb371,
	seagreen = 0x2e8b57,
	honeydew = 0xf0fff0,
	darkseagreen = 0x8fbc8f,
	palegreen = 0x98fb98,
	lightgreen = 0x90ee90,
	limegreen = 0x32cd32,
	lime = 0x00ff00,
	forestgreen = 0x228b22,
	green = 0x008000,
	darkgreen = 0x006400,
	lawngreen = 0x7cfc00,
	chartreuse = 0x7fff00,
	greenyellow = 0xadff2f,
	darkolivegreen = 0x556b2f,
	yellowgreen = 0x9acd32,
	olivedrab = 0x6b8e23,
	ivory = 0xfffff0,
	beige = 0xf5f5dc,
	lightyellow = 0xffffe0,
	lightgoldenrodyellow = 0xfafad2,
	yellow = 0xffff00,
	olive = 0x808000,
	darkkhaki = 0xbdb76b,
	palegoldenrod = 0xeee8aa,
	lemonchiffon = 0xfffacd,
	khaki = 0xf0e68c,
	gold = 0xffd700,
	cornsilk = 0xfff8dc,
	goldenrod = 0xdaa520,
	darkgoldenrod = 0xb8860b,
	floralwhite = 0xfffaf0,
	oldlace = 0xfdf5e6,
	wheat = 0xf5deb3,
	orange = 0xffa500,
	moccasin = 0xffe4b5,
	papayawhip = 0xffefd5,
	blanchedalmond = 0xffebcd,
	navajowhite = 0xffdead,
	antiquewhite = 0xfaebd7,
	c_tan = 0xd2b48c,
	burlywood = 0xdeb887,
	darkorange = 0xff8c00,
	bisque = 0xffe4c4,
	linen = 0xfaf0e6,
	peru = 0xcd853f,
	peachpuff = 0xffdab9,
	sandybrown = 0xf4a460,
	chocolate = 0xd2691e,
	saddlebrown = 0x8b4513,
	seashell = 0xfff5ee,
	sienna = 0xa0522d,
	lightsalmon = 0xffa07a,
	coral = 0xff7f50,
	orangered = 0xff4500,
	darksalmon = 0xe9967a,
	tomato = 0xff6347,
	salmon = 0xfa8072,
	mistyrose = 0xffe4e1,
	lightcoral = 0xf08080,
	snow = 0xfffafa,
	rosybrown = 0xbc8f8f,
	indianred = 0xcd5c5c,
	red = 0xff0000,
	brown = 0xa52a2a,
	firebrick = 0xb22222,
	darkred = 0x8b0000,
	maroon = 0x800000,
	white = 0xffffff,
	whitesmoke = 0xf5f5f5,
	gainsboro = 0xdcdcdc,
	lightgrey = 0xd3d3d3,
	silver = 0xc0c0c0,
	darkgray = 0xa9a9a9,
	gray = 0x808080,
	dimgray = 0x696969,
	black = 0x000000
};

typedef struct	s_colour_arr
{
	int			colour[137];
}				t_colour_arr;

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

typedef struct	s_complex {
	double		re;
	double		im;
}				t_complex;

typedef struct	s_dual {
	t_complex	one;
	t_complex	sq;
}				t_dual;

typedef struct	s_vec3 {
	double		x;
	double		y;
	double		z;
	double		c_scale;
}				t_vec3;

typedef struct	s_camera
{
	double		dist;
	t_vec3		offset;
	int			colour;
	double		time;
	double		old_time;
	double		frame;
	int			mode;
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
	t_cam		cur;
	char		*set;
}				t_vars;

typedef struct	s_rgb {
	double r;
	double g;
	double b;
}				t_rgb;

typedef struct	s_hsv{
	double h;
	double s;
	double v;
}				t_hsv;

typedef struct	s_arg {
	t_data		*data;
	t_uv		screen;
	t_cam		*cam;
	void		(*f)(t_data*, t_uv, t_cam*);
	pthread_t	*tid;
}				t_arg;

typedef struct	s_col_trans{
	double		hh;
	double		p;
	double		q;
	double		t;
	double		ff;
}				t_col_trans;

t_complex		g42_cadd(t_complex x, t_complex y);

double			g42_cabs(t_complex c);

t_complex		g42_cmultiply(t_complex x, t_complex y);

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

t_rgb			g42_hsv_to_rgb(t_hsv in);

t_hsv			g42_rgb_to_hsv(t_rgb in);

int				g42_rgb_to_hex(t_rgb rgb);

int				g42_get_colours(int index);
#endif
