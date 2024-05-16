# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 12:43:39 by jewlee            #+#    #+#              #
#    Updated: 2024/05/16 16:11:57 by jewlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -f
SRCS = ./srcs/main.c \
	./srcs/init.c \
	./srcs/check.c \
	./srcs/free.c \
	./srcs/utils.c \
	./srcs/threads.c \
	./srcs/behave.c \
	./srcs/behave_utils.c
INCLUDE = ./include
OBJS = $(SRCS:.c=.o)

all : make_mandatory

make_mandatory : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(INCLUDE) -o $(NAME)
	@ touch make_mandatory

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	@ $(RM) make_mandatory

re : fclean all

.PHONY : all clean fclean re
