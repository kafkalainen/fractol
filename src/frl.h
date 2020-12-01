/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:32:21 by jnivala           #+#    #+#             */
/*   Updated: 2020/12/01 15:14:35 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef frl_H
#define frl_H
#define ESC 65307
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_Q 113
#define KEY_E 101
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_C 99
#define KEY_R 114
#define KEY_F 102
#define KEY_G 103
#define KEY_H 104
#define LEFT 65361
#define RIGHT 65363
#define UP 65362
#define DOWN 65364
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define INVALID_CHARACTERS 2
#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080
#define MENU_HEIGHT 200
#define BUFF_SIZE 1024
#define SNOW 0xfffafa
#define MISTYROSE 0xffe4e1
#define LIGHTBLUE 0xadd8e6
#define POWDERBLUE 0xb0e0e6
#define PALETURQUOISE 0xafeeee
#define TURQUOISE 0x5ca08e
#define PALEGREEN 0x98fb98
#define LIMEGREEN 0x32cd32
#define LIGHTYELLOW 0xffffe0
#define SANDYBROWN 0xf4a460
#define ORANGE 0xffa500
#define HOTPINK 0xff69b4
#define LIGHTPINK 0xffb6c1
#define VIOLETRED 0xd02090
#include "g42.h"
#include <string.h>

int frl_change_colour(int keycode, t_vars *vars);

int frl_check_valid_depth(char *str, char *validate);

size_t frl_count_height(char const *s, t_map *map);

size_t *frl_count_width(char const *s, t_map *map);

double frl_depth_parser(t_map *map, char *elem);

double frl_double_parser(int begin, int end);

void frl_draw_wire(t_data *data, t_map *map, t_uv *coord, int colour);

void frl_draw_line(t_data *data, t_uv p0, t_uv p1, int colour);

int frl_draw_menu(t_data *data, int colour);

int frl_draw_background(t_data *data);

int frl_draw_instructions_right(t_data *data, t_uv coord);

int frl_draw_instructions_left(t_data *data, t_uv coord);

void frl_draw_title(t_data *data, t_uv coord);

int frl_error(char *message);

int frl_file_reader(t_map *map, char *filename);

int frl_front_object(int keycode, t_vars *vars);

int frl_handle_keypress(int keycode, t_vars *vars);

size_t frl_idx(size_t x, size_t y, t_map *map);

int frl_init_view(t_map *map, t_cam *cur);

int frl_init_camera(t_cam *cam);

t_vars *frl_init_vars(void);

int frl_iso_object(int keycode, t_vars *vars);

int frl_move_object(int keycode, t_vars *vars);

int frl_reset_object(int keycode, t_vars *vars);

int frl_rotate_object(int keycode, t_vars *vars);

int frl_scale_object(int keycode, t_vars *vars);

t_uv *frl_translate_coordinates(t_map *map, t_cam *cam);

int frl_count_colour_scale(t_map *map);

t_vars *frl_clean(t_vars **vars);

char *frl_del_vars(t_vars **vars);

int frl_manipulate_y(int keycode, t_vars *vars);

#endif
