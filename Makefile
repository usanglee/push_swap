# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 20:21:55 by ulee              #+#    #+#              #
#    Updated: 2021/07/24 21:30:29 by ulee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_C = checker
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
INCS = -I./libft -I./
LIBFT = -L./libft -lft
RM = rm -f

FILE = 	00_main\
		01_node_io\
		02_argument\
		03_check\
		04_make\
		05_quick_sort\
		06_command\
		07_command_both\
		08_sort\
		09_small_sort\
		10_small_sort_3_a\
		11_small_sort_3_b\
		12_free\
		99_etc

CHECKER = 	checker\
			01_node_io\
			02_argument\
			03_check\
			04_make\
			05_quick_sort\
			06_command\
			07_command_both\
			12_free\
			99_etc

SRCS = $(addprefix ./, $(addsuffix .c, $(FILE)))
OBJS = $(addprefix ./, $(addsuffix .o, $(FILE)))

SRCS_C = $(addprefix ./, $(addsuffix .c, $(CHECKER)))
OBJS_C = $(addprefix ./, $(addsuffix .o, $(CHECKER)))

%.o: %.c
	$(CC) $(INCS) -c $< -o $@

all : $(NAME) $(NAME_C)

$(NAME) : $(OBJS)
	make -C ./libft
	$(CC) $(LIBFT) $(OBJS) -o $@

$(NAME_C) : $(OBJS_C)
	make -C ./libft
	$(CC) $(LIBFT) $(OBJS_C) -o $@

clean:
	make -C ./libft clean
	$(RM) $(OBJS)
	$(RM) $(OBJS_C)

fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)
	$(RM) $(NAME_C)

re: clean all

.PHONY: all clean fclean re
