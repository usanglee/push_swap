# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 20:21:55 by ulee              #+#    #+#              #
#    Updated: 2021/07/22 23:47:42 by ulee             ###   ########.fr        #
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
		99_etc

CHECKER = 	checker\
			01_node_io\
			02_argument\
			03_check\
			04_make\
			05_quick_sort\
			06_command\
			07_command_both\
			99_etc

SRCS = $(addprefix ./, $(addsuffix .c, $(FILE)))
OBJS = $(addprefix ./, $(addsuffix .o, $(FILE)))

SRCS_C = $(addprefix ./, $(addsuffix .c, $(CHECKER)))
OBJS_C = $(addprefix ./, $(addsuffix .o, $(CHECKER)))

%.o: %.c
	$(CC) $(INCS) -c $< -o $@

$(NAME) : $(OBJS) $(NAME_C)
	make -C ./libft
	$(CC) $(LIBFT) $(OBJS) -o $@

$(NAME_C) : $(OBJS_C)
	make -C ./libft
	$(CC) $(LIBFT) $(OBJS_C) -o $@

all : $(NAME)

bonus : $(NAME_C)

clean:
	make -C ./libft clean
	$(RM) $(OBJS)
	$(RM) $(OBJS_C)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_C)
	$(RM) ./libft/libft.a

re: clean all

.PHONY: all clean fclean re
