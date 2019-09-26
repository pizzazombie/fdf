# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/13 14:06:41 by dholiday          #+#    #+#              #
#    Updated: 2019/08/30 16:40:53 by dholiday         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FDF = fdf

LIBFTPATH = ./libft
LIBFT = $(LIBFTPATH)/libft.a

MLXPATH = ./minilibx_macos
MLX = $(MLXPATH)/libmlx.a

FLAGS = -I $(MLXPATH) -L $(MLXPATH) -lmlx -framework OpenGL -framework AppKit -Wall -Werror -Wextra

SRC = main.c algorithm.c read_file.c point_to_paint.c  action.c change_map.c rotate.c put_text.c mouse.c 
OBJ = $(SRC:%.c=%.o)

NAME =  $(MLX) $(LIBFT) $(FDF)

all: $(NAME)

$(LIBFT) :
	make -C $(LIBFTPATH)

$(OBJ) : ./fdf.h

$(MLX) :
	make -C $(MLXPATH)

$(MAIN) :  $(MLX) $(OBJ) $(LIBFT)
		gcc $(FLAGS) -I. -I$(LIBFTPATH) -Iinc  $(LIBFT) $(OBJ) -o $(FDF)

clean:
	make clean -C $(LIBFTPATH)
	make clean -C $(MLXPATH)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFTPATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
		
