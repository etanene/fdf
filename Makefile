# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntothmur <ntothmur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 18:05:58 by afalmer-          #+#    #+#              #
#    Updated: 2019/10/22 14:10:15 by ntothmur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FDF = ./fdf
SRC = main.c utils.c validate.c keys.c control.c rotation.c draw_map.c menu.c

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

LIB = libft/libft.a
FDFLIB = minilibx_macos/libmlx.a
FLAGS = -Wall -Wextra -Werror -g
HEADER = includes/fdf.h

all: $(FDF)

$(FDF): $(LIB) $(FDFLIB) $(OBJ_DIR) $(OBJ)
	gcc $(FLAGS) $(OBJ) -L./libft -lft -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit -o $(FDF)

$(OBJ_DIR):
	mkdir obj/

$(OBJ_DIR)%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@ -I./includes -I./libft/includes/ -I./minilibx_macos/

$(LIB):
	make -C libft/

$(FDFLIB):
	make -C minilibx_macos/

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft/
	make clean -C minilibx_macos/

fclean: clean
	rm -rf $(FDF)
	make fclean -C libft/
	make clean -C minilibx_macos/

re: fclean all
