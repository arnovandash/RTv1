# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/25 11:55:33 by arnovan-          #+#    #+#              #
#    Updated: 2016/07/15 18:06:24 by kchetty          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=rtv1

CC=gcc

CFLAGS=-Wall -Wextra -Werror -g

LINUX=-I/usr/X11/include -L/usr/X11/lib -lX11 -lXext -lmlx

MAC=-L/usr/lib -lmlx -framework OpenGL -framework AppKit

RM=rm -f

INC_LIBFT= -L. -lft

FCLEAN_LIB=make -C libft/ fclean

PATH_SRC= ./src/

PATH_HD= -I includes/

SRC = $(PATH_SRC)main.c $(PATH_SRC)controls.c $(PATH_SRC)errors.c\
		$(PATH_SRC)get_scene.c $(PATH_SRC)draw.c $(PATH_SRC)ft_math.c\
		$(PATH_SRC)ft_math2.c $(PATH_SRC)sort_list.c

OBJ = main.o controls.o errors.o get_scene.o draw.o ft_math.o ft_math2.o\
	  sort_list.o

$(NAME):
	@echo "Compiling binaries..."
	@make re -C libft/	
	@$(CC) $(CFLAGS) $(PATH_HD) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -lm $(INC_LIBFT) $(MAC)
	@echo "Compilation was successful!"

all: $(NAME)

x11:
	@echo "Compiling binaries..."
	@make re -C libft/	
	@$(CC) $(CFLAGS) $(PATH_HD) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -lm $(INC_LIBFT) $(LINUX)
	@echo "Compilation was successful!"

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ)
	@echo "Cleaning libft object files..."
	@make -C libft/ clean
	@echo "Done cleaning!"

fclean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ)
	@echo "Cleaning libft object & binary files..."
	@make -C libft/ fclean
	@echo "Cleaning binaries..."
	@$(RM) $(NAME)
	@echo "Done cleaning!"

re: fclean all
