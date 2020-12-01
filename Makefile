# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 09:44:44 by jnivala           #+#    #+#              #
#    Updated: 2020/12/01 16:13:05 by jnivala          ###   ########.fr        #
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
	g42_mlx_draw_line_dda.c\
	g42_draw_line_bre.c\
	g42_mlx_draw_x_y_line.c\
	g42_mlx_draw_diagonal.c\
	g42_solid_square.c\
	g42_cross_product.c\
	g42_dot_product.c\
	g42_normalize_vector.c\
	g42_2d_to_uv.c\
	g42_ndc_to_raster_space.c\
	g42_rotate_x_axis.c\
	g42_rotate_y_axis.c\
	g42_rotate_z_axis.c\
	g42_scale_point.c\
	g42_mod_pts.c\
	g42_mod_vec.c\
	g42_multi_vec_matrix.c\
	g42_translate.c\
	g42_str_pxl.c\
	g42_pxl_alphabet.c\
	g42_pxl_numbers.c\
	g42_hex_to_trgb.c\
	g42_trgb_to_hex.c\
	g42_c_grad.c\
	g42_scale_y.c\
	frl_handle_keypress.c\
	frl_draw_wire.c\
	frl_draw_line.c\
	frl_idx.c\
	frl_move_object.c\
	frl_scale_object.c\
	frl_rotate_object.c\
	frl_double_parser.c\
	frl_reset_object.c\
	frl_iso_object.c\
	frl_front_object.c\
	frl_init_camera.c\
	frl_init_view.c\
	frl_init_vars.c\
	frl_draw_menu.c\
	frl_draw_background.c\
	frl_draw_instructions_left.c\
	frl_draw_instructions_right.c\
	frl_draw_title.c\
	frl_count_colour_scale.c\
	frl_error.c\
	frl_clean.c\
	frl_del_vars.c\
	frl_change_colour.c\
	frl_manipulate_y.c\
	frl_translate_coordinates.c\

HEADERS = $(addprefix $S,\
		frl.h\
		g42.h\
	)
SRC = $(addprefix $S, $(SRC_LIST))
OBJ = $(SRC:$S%=$O%.o)
RM = /bin/rm -f
RMDIR = /bin/rmdir
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = $(addprefix -I,$(include_dirs))

.PHONY: all clean fclean re debug

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
	$(CC) $(OBJ) -Lmlx_linux -lmlx -L$(INCLIB) -Llibft/ -lft -Imlx_linux -lXext -lX11 -lm -lz -o $@

cleanobj:
	$(RM) $(wildcard $(OBJ))

cleanobjdir: cleanobj
	$(RMDIR) $O

clean: cleanobjdir
	make -C $(mlx_dir) clean
	make -C $(libft_dir) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: $(MLX) $(objects_dir) $(OBJ)
	make -C $(libft_dir) fclean && make debug -C $(libft_dir)
	$(CC) $(OBJ) -Lmlx_linux -lmlx -L$(INCLIB) -Llibft/ -lft -Imlx_linux -lXext -lX11 -lm -lz -o $@
