# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 09:44:44 by jnivala           #+#    #+#              #
#    Updated: 2020/12/23 18:46:15 by jnivala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

S = src/
O = obj/
mlx_dir = mlx_linux/
libft_dir = libft/
LIBFT = $(libft_dir)libft.a
include_dirs = libft /usr/include $(mlx_dir) $(source_dir)
INC = /usr/include
INCLIB = $(INC)/../lib
MLX = $(mlx_dir)libmlx.a

SRC_LIST = \
	main.c\
	g42_get_transparency.c\
	g42_get_blue.c\
	g42_get_green.c\
	g42_get_red.c\
	g42_create_trgb.c\
	g42_invert_trgb.c\
	g42_mlx_pixel_put.c\
	g42_solid_square.c\
	g42_str_pxl.c\
	g42_pxl_alphabet.c\
	g42_pxl_numbers.c\
	g42_hex_to_trgb.c\
	g42_trgb_to_hex.c\
	g42_hsv_to_rgb.c\
	g42_rgb_to_hsv.c\
	g42_rgb_to_hex.c\
	g42_get_colours.c\
	g42_linear_mapping.c\
	frl_burningship.c\
	frl_clean.c\
	frl_change_colours.c\
	frl_change_colour_mode.c\
	frl_draw_background.c\
	frl_draw_fractal.c\
	frl_draw_instructions_left.c\
	frl_draw_instructions_right.c\
	frl_draw_menu.c\
	frl_draw_title.c\
	frl_error.c\
	frl_handle_btn.c\
	frl_handle_key.c\
	frl_handle_mov.c\
	frl_image_loop.c\
	frl_init_camera.c\
	frl_init_vars.c\
	frl_init_windows.c\
	frl_julia.c\
	frl_mandelbrot.c\
	frl_mutate_iterations.c\
	frl_normalize_coordinates.c\
	frl_paint_current_fractal.c\
	frl_reset_colour.c\
	frl_reset.c\
	frl_move_fractal.c\
	frl_colour_scheme.c\
	frl_usage.c\
	frl_validate_sets.c\
	frl_zoom_fractal.c\
	frl_handle_focus.c\
	frl_newton.c\
	frl_nova.c\
	frl_magnet.c\
	frl_tricorn.c\
	frl_reset_julia.c\

HEADERS = $(addprefix $S,\
		frl.h\
		g42.h\
	)
SRC = $(addprefix $S, $(SRC_LIST))
OBJ = $(SRC:$S%=$O%.o)
RM = /bin/rm -f
RMDIR = /bin/rmdir
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = $(addprefix -I,$(include_dirs))

.PHONY: all clean fclean re

all: $(NAME)

$O:
	mkdir -p $@

$(OBJ): | $O

$(OBJ): $O%.o: $S% $(HEADERS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	make -C $(libft_dir)

$(MLX):
	make -C $(mlx_dir)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx -L$(INCLIB) -Llibft/ -lft -Imlx_linux -lpthread -lXext -lX11 -lm -lz -o $@

cleanobj:
	$(RM) $(wildcard $(OBJ))

cleanobjdir: cleanobj
	$(RMDIR) $O

clean: cleanobjdir
	make -C $(mlx_dir) clean
	make -C $(libft_dir) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all
