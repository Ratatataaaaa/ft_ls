# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwing <cwing@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 12:54:38 by cwing             #+#    #+#              #
#    Updated: 2020/05/02 21:01:26 by cwing            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc
FLAGS = -Wall #-Wextra -O3
#LIBRARIES_MAC = -lft -L$(LIBFT_DIRECTORY)

#LIBFT = $(LIBFT_DIRECTORY)libft.a
#LIBFT_DIRECTORY = libft/

SRC_DIRECTORY = src/
SRC_LIST = *.c
SRC = $(addprefix $(SRC_DIRECTORY), $(SRC_LIST))

GREEN = \033[0;32;1m
RED = \033[0;31;1m
RESET = \033[0m

FILES = src/dir.c \
src/flag.c \
src/info.c \
src/main.c \
src/print.c \
src/s_dir.c \
src/sort_list.c \
src/utils.c \
src/utils2.c \
F_flag/c


all: $(NAME)

$(NAME):
	@echo "\n$(NAME): $(GREEN)Создание исполняемого файла$(RESET)"
	@make -C libft
	@gcc $(CFLAGS) $(FILES) libft/libft.a -o $(NAME)
	@echo "$(NAME): $(GREEN)$(NAME) Готово$(RESET)"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Создание $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)
%.o: %.c
	$(CC) $(FLAGS) -c $< -I.

clean:
	@make -sC $(LIBFT_DIRECTORY) clean

fclean:
	#@make fclean -C libft 
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) было удалено$(RESET)"


re: fclean all

.PHONY: all clean fclean re
