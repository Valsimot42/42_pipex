# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 12:05:46 by tbolkova          #+#    #+#              #
#    Updated: 2023/04/19 18:08:54 by tbolkova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIB = libftprintf.a
SRC = src
INC = inc
LIB_F = Library/Ft_printf
CC = gcc
LIBS = $(LIB_F)/$(LIB)
CFLAGS = -g -o3 -I $(INC)
SRC_F =	src/errors.c \
		src/extra.c \
		src/files.c \
		src/main.c \
		src/path.c \
		src/pipex.c 


OBJ_F = $(SRC_F:.c=.o)

GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;34m
DEF_COLOR = \033[0;39m

all: $(NAME)

$(NAME): $(OBJ_F) $(LIBS)
	@$(CC) $^ -o3 -o $(NAME)
	@echo "$(GREEN)pipex compiled!$(DEF_COLOR)"

$(LIBS): 
	@make -C $(LIB_F)
	@echo "$(BLUE)libft is done!$(DEF_COLOR)"

clean:
	@rm -rf $(OBJ_F)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB_F)
	@echo "$(YELLOW)Everything was cleaned $(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re