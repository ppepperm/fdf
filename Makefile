# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/17 12:14:41 by ppepperm          #+#    #+#              #
#    Updated: 2019/11/17 12:14:43 by ppepperm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf
SRC := main.c rotate.c inits.c draw_isometric.c
OBJ := $(patsubst %.c, %.o, $(SRC))
CFLAGS := -Wall -Wextra -Werror
LIB_FLAG := -L libft/ -lft  -L minilibx_macos -lmlx -framework OpenGL -framework AppKit
LINUX_FLAG := -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 -lm
INCLUDES := .

all: $(NAME)

%.o : src/%.c $(INCLUDES)fillit.h
		@gcc -c $(CFLAGS) -I $(INCLUDES) $< -o $@
		@echo $(patsubst src/%.c, %, $<)

$(NAME): $(OBJ)
		@make -C libft
		@make -C minilibx_macos
		@gcc -o $(NAME) $(CFLAGS) $(OBJ) $(LIB_FLAG)
		@echo "DONE"

$LINUX : $(OBJ)
		@make -C libft
		@gcc -o $(NAME) $(CFLAGS) $(OBJ) $(LIB_FLAG)
		@echo "DONE"

clean:
		@rm -f $(OBJ)
		@make -C libft clean

fclean: clean
		@rm -f $(NAME)
		@make -C libft fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
