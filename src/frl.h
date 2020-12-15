/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:32:21 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/15 21:37:19 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRL_H
# define FRL_H
# define ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_Q 113
# define KEY_E 101
# define KEY_1 49
# define KEY_2 50
# define KEY_3 51
# define KEY_4 52
# define KEY_C 99
# define KEY_R 114
# define KEY_F 102
# define KEY_G 103
# define KEY_H 104
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define ZOOM_IN 4
# define ZOOM_OUT 5
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define INVALID_CHARACTERS 2
# define WIN_W 1000
# define WIN_H 750
# define MENU_HEIGHT 120
# define BUFF_SIZE 1024
# define MAX_THREADS 25
# include "g42.h"
# include <string.h>

void		frl_burningship(t_data *data, t_uv screen, t_cam *cam);

int			frl_change_colour_mode(int buttoncode, t_vars *vars);

int			frl_change_colours(int buttoncode, t_vars *vars);

t_vars		*frl_clean(t_vars **vars);

int			frl_draw_background(t_data *data);

int			frl_draw_fractal(t_cam *cam, t_data *data, char *str);

int			frl_draw_instructions_left(t_data *data, t_uv coord);

int			frl_draw_instructions_right(t_data *data, t_uv coord);

int			frl_draw_menu(t_data *data, int colour);

void		frl_draw_title(t_data *data, t_uv coord);

int			frl_error(char *message);

int			frl_handle_btn(int buttoncode, int x, int y, t_vars *vars);

int			frl_handle_key(int keycode, t_vars *vars);

int			frl_handle_mov(int x, int y, t_vars *vars);

int			frl_image_loop(t_vars *vars);

int			frl_init_camera(t_cam *cam);

t_vars		**frl_init_vars(int argc);

int			frl_init_windows(t_vars **vars, int *windows, char **argv,
			int argc);

void		frl_paint_current_fractal(t_data *data, t_cam *cam,
			void (*f)(t_data*, t_uv, t_cam*));

void		frl_mandelbrot(t_data *data, t_uv screen, t_cam *cam);

t_complex	frl_normalize_coordinates(int x, int y, t_cam *cam);

void		frl_julia(t_data *data, t_uv screen, t_cam *cam);

int			frl_move_fractal(int keycode, t_vars *vars);

int			frl_colour_scheme(int i, t_cam *cam);

int			frl_zoom_fractal(int buttoncode, int x, int y, t_vars *vars);

int			frl_reset_colour(int buttoncode, t_vars *vars);

int			frl_reset(int buttoncode, t_vars *vars);

int			frl_usage(void);

int			frl_validate_sets(int argc, char **argv);

int			frl_mutate_iterations(int buttoncode, t_vars *vars);
#endif
