# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 13:27:03 by iubieta-          #+#    #+#              #
#    Updated: 2024/03/29 13:27:03 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./include -I./srcs/libs/libft -I./srcs/libs/printf
LIBS = -L./srcs/libs/libft -lft -L./srcs/libs/printf -lftprintf

SRCS_DIR = ./srcs
OBJS_DIR = ./objs
SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): libs $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
libs:
	$(MAKE) -C ./srcs/libs/printf
	$(MAKE) -C ./srcs/libs/libft

clean:
	$(MAKE) -C ./srcs/libs/printf fclean
	$(MAKE) -C ./srcs/libs/libft fclean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
