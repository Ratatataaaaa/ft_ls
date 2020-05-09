# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwing <cwing@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 12:54:38 by cwing             #+#    #+#              #
#    Updated: 2020/05/09 16:06:22 by cwing            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = src/dir.c \
	src/flag.c \
	src/info.c \
	src/main.c \
	src/print.c \
	src/print2.c \
	src/s_dir.c \
	src/sort_list.c \
	src/utils.c \
	src/utils2.c 

INC = includes/
CC = gcc
FLAGS = -Wall -Wextra -Werror -I $(INC)
OBG = $(SRC:.c=.o)
LIBFT = libft/

GREEN = \033[0;32;1m
RED = \033[0;31;1m
RESET = \033[0m

all: $(NAME)

%.o: %.c
	@printf "$(RED)[ft_ls] Compiling [...]\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN)[ft_ls] Compiling [.!.]\r$(RESET)"

$(NAME): $(OBG) libra
	@$(CC) $(FLAGS) $(OBG) -o $(NAME) $(LIBFT)/libft.a
	@printf "$(GREEN)[ft_ls] Compiled successfuly! [OK]$(RESET)\n"

libra:
	@make -C libft

clean:
	@/bin/rm -f $(OBG)
	@make clean -C libft
	@printf "$(RED)[ft_ls] Removed object files!$(RESET)\n"

fclean: clean
	@make fclean -C libft 
	@rm -f $(NAME)
	@printf "$(RED)[ft_ls] Deleted successfuly! [OK]\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re
