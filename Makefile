# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwing <cwing@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 12:54:38 by cwing             #+#    #+#              #
#    Updated: 2020/03/03 15:37:36 by cwing            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc
FLAGS = -Wall #-Wextra -O3
LIBRARIES_MAC = -lft -L$(LIBFT_DIRECTORY)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = libft/

SRC_DIRECTORY = src/
SRC_LIST = *.c
SRC = $(addprefix $(SRC_DIRECTORY), $(SRC_LIST))

GREEN = \033[0;32;1m
RED = \033[0;31;1m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(SRC) -o $(NAME) $(LIBRARIES_MAC)
	@echo "\n$(NAME): $(GREEN)Создание исполняемого файла$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) Готово$(RESET)"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Создание $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)
%.o: %.c
	$(CC) $(FLAGS) -c $< -I.

clean:
	@make -sC $(LIBFT_DIRECTORY) clean

fclean:
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) было удалено$(RESET)"


re: fclean all