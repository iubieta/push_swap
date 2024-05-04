# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 15:38:39 by iubieta-          #+#    #+#              #
#    Updated: 2024/05/04 13:15:46 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDE = libft.h
SRCS = $(shell find "." -name "*.c")			
OBJS = ${SRCS:.c=.o}
BONUS = $(shell find "." -name "*_bonus.c")
BONUS_OBJS = ${BONUS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar csr
RM = rm -rf

all : ${NAME}
	@touch ${NAME}

${NAME} : ${OBJS} ${INCLUDE}
	${AR} ${NAME} $^
	@echo "LIBFT COMPILED\n"

bonus: ${OBJS} ${BONUS_OBJS} ${INCLUDE}
	${AR} ${NAME} ${OBJS} ${BONUS_OBJS}
	@echo "LIBFT BONUS COMPILED\n"

clean :
	@${RM} ${OBJS} ${BONUS_OBJS}

fclean : clean
	@${RM} ${NAME}
	@echo "CLEANED"

re : fclean all

.PHONY: all clean fclean re bonus