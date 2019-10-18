# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 17:30:17 by afalmer-          #+#    #+#              #
#    Updated: 2019/05/16 15:18:31 by afalmer-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c ft_bzero.c ft_itoa.c ft_tolower.c ft_toupper.c \
		get_next_line.c ft_pow.c ft_numlen.c ft_unumlen.c ft_free_multiarr.c

SRCDIR_IS = ft_is/
SRC_IS =	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c

SRCDIR_LST = ft_lst/
SRC_LST =	ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
			ft_lstnew.c

SRCDIR_MEM = ft_mem/
SRC_MEM =	ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memdel.c ft_memmove.c ft_memset.c

SRCDIR_PRINTF = ft_printf/
SRC_PRINTF =	ft_bigint_op.c ft_bigint.c ft_buff_manage.c ft_parse_nums.c \
				ft_print_cs.c ft_print_diuoxb.c ft_print_e.c ft_print_f.c \
				ft_print_options.c ft_print_prk.c ft_printf.c ft_set_options.c \
				ft_utils_num.c ft_utils_str.c

SRCDIR_PUT = ft_put/
SRC_PUT =	ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c \
			ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c

SRCDIR_STR = ft_str/
SRC_STR =	ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
			ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
			ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
			ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
			ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c \
			ft_strtrim.c

OBJDIR = obj/
OBJ = $(addprefix $(OBJDIR), $(SRC:%.c=%.o) \
								$(SRC_IS:%.c=%.o) \
								$(SRC_IS:%.c=%.o) \
								$(SRC_LST:%.c=%.o) \
								$(SRC_MEM:%.c=%.o) \
								$(SRC_PRINTF:%.c=%.o) \
								$(SRC_PUT:%.c=%.o) \
								$(SRC_STR:%.c=%.o))

FLAG = -Wall -Wextra -Werror

HEADER = includes/

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJDIR):
	mkdir obj/

$(OBJDIR)%.o: %.c
	gcc $(FLAG) -c $< -o $@ -I $(HEADER)

$(OBJDIR)%.o: $(SRCDIR_IS)%.c
	gcc $(FLAG) -c $< -o $@ -I $(HEADER)

$(OBJDIR)%.o: $(SRCDIR_LST)%.c
	gcc $(FLAG) -c $< -o $@ -I $(HEADER)

$(OBJDIR)%.o: $(SRCDIR_MEM)%.c
	gcc $(FLAG) -c $< -o $@ -I $(HEADER)

$(OBJDIR)%.o: $(SRCDIR_PRINTF)%.c
	gcc $(FLAG) -c $< -o $@ -I $(HEADER)

$(OBJDIR)%.o: $(SRCDIR_PUT)%.c
	gcc $(FLAG) -c $< -o $@ -I $(HEADER)

$(OBJDIR)%.o: $(SRCDIR_STR)%.c
	gcc $(FLAG) -c $< -o $@ -I $(HEADER)

clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
