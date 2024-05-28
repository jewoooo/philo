# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 11:48:05 by jewlee            #+#    #+#              #
#    Updated: 2024/05/28 13:21:39 by jewlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = ./srcs/main_bonus.c \
	./srcs/init_bonus.c \
	./srcs/behave_bonus.c \
	./srcs/behave_utils_bonus.c \
	./srcs/error_bonus.c \
	./srcs/utils1_bonus.c \
	./srcs/utils2_bonus.c \
	./srcs/thread_bonus.c \
	./srcs/processes_bonus.c \
	./srcs/free_bonus.c
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
