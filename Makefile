# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvuente <mvuente@student.21-school.ru      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/27 10:03:43 by mvuente           #+#    #+#              #
#    Updated: 2020/05/27 12:53:17 by mvuente          ###   ########.fr        #
#                                                                              #
# **************************************************************************** 

NAME = miniRT
MINIRT = minirt.a
MLX = libmlx.dylib
LIBFT = libft.a

SRC = 		src/utils.c \
			src/colorscalc.c \
			src/converters.c \
			src/crosspoints.c \
			src/lights.c \
			src/shadows.c \
			src/rotation.c \
			src/saving.c \
			src/imaginarium.c \
			src/scener.c \
			src/list_operations.c \
			src/gnl.c \
			src/parsing.c \
			src/atoisint.c \
			src/figparsers.c \
			src/camparser.c \
			src/errors.c \
			src/errorsnext.c \
			src/circparsers.c \
			src/camera_editor.c \
			src/one_vector_ops.c \
			src/two_vector_ops.c \
			src/ray_parcers.c \
			src/constantparsers.c \
			src/utilsparsers.c \
			src/atoisfloat.c \
			src/equations.c \
			src/list_circ_operations.c \
			src/validators.c \
			src/cleaner.c \
			src/minirt.c

SRC_LIB_DIR = SRC/libft/
SRC_MLX_DIR = SRC/minilibx_mms_20200219/

OBJ = $(SRC:.c=.o)
RT_H = src/miniRT.h

CC = gcc

FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(SRC_LIB_DIR)
	cp $(SRC_LIB_DIR)$(LIBFT) .
	make -C $(SRC_MLX_DIR)
	cp $(SRC_MLX_DIR)$(MLX) .
	$(CC) $(FLAGS) $(OBJ) -framework OpenGL -framework AppKit -lz -L. $(LIBFT) -L. $(MLX) -o $(NAME)

%.o: %.c  $(RT_H)
	$(CC) $(FLAGS) -c $< -o $@ -I $(RT_H)
 
clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(MLX)

re: fclean all

