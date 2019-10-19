# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 18:05:58 by afalmer-          #+#    #+#              #
#    Updated: 2019/10/19 20:28:38 by afalmer-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FDF = ./fdf
SRC = main.c utils.c validate.c keys.c control.c rotation.c

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

LIB = libft/libft.a
FLAGS = -Wall -Wextra -Werror -g
HEADER = includes/fdf.h

all: $(FDF)

$(FDF): $(LIB) $(OBJ_DIR) $(OBJ)
	gcc $(FLAGS) $(OBJ) -L./libft -lft -o $(FDF)

$(OBJ_DIR):
	mkdir obj/

$(OBJ_DIR)%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@ -I./includes -I./libft/includes/

$(LIB):
	make -C libft/

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft/

fclean: clean
	rm -rf $(FDF)
	make fclean -C libft/

re: fclean all
