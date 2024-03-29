# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 11:07:07 by sejinkim          #+#    #+#              #
#    Updated: 2023/06/10 10:52:23 by sejinkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = fdf
HDR_DIR = ./includes/
HDR = $(HDR_DIR)fdf.h $(HDR_DIR)fdf_hook.h
SRCS_MANDATORY = \
	./srcs/fdf_main.c \
	./srcs/map/fdf_map_line.c ./srcs/map/fdf_map_info.c \
	./srcs/map/fdf_split.c ./srcs/map/fdf_color.c \
	./srcs/map/fdf_pos.c \
	./srcs/proj/fdf_rotation.c ./srcs/proj/fdf_projection.c \
	./srcs/proj/fdf_transformation.c \
	./srcs/proj/fdf_draw_img.c ./srcs/proj/fdf_draw_line.c \
	./srcs/hook/fdf_hook.c ./srcs/hook/fdf_hook2.c

OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
MLX_DIR = ./minilibx/
MLX = $(MLX_DIR)libmlx.a
INCLUDE = -I$(MLX_DIR) -I$(HDR_DIR)
LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(MLX) $(OBJS_MANDATORY) 
	$(CC) $(CFLAGS) $(INCLUDE) $(LIB) $^ -o $(NAME)

%.o : %.c $(HDR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(MLX) :
	make -C $(MLX_DIR)

clean :
	rm -f $(OBJS_MANDATORY)

fclean : 
	make clean
	make clean -C $(MLX_DIR)
	rm -f $(NAME)

re :
	make clean 
	rm -f $(NAME)
	make all

.PHONY : all clean fclean re