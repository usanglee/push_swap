# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 20:21:55 by ulee              #+#    #+#              #
#    Updated: 2021/06/07 19:51:01 by ulee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_C = checker
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
INCS = -I./libft -I./
LIBFT = -L./libft -lft
RM = rm -f

FILE = 	main\
		list\
		command\
		command_both\
		etc\
		argument\
		check\
		make\
		sort_arr\
		sort
# FILE_C = checker\


SRCS = $(addprefix ./, $(addsuffix .c, $(FILE)))
OBJS = $(addprefix ./, $(addsuffix .o, $(FILE)))

# SRCS_C = $(addprefix ./, $(addsuffix .c, $(FILE_C)))
# OBJS_C = $(addprefix ./, $(addsuffix .o, $(FILE_C)))

%.o: %.c
	$(CC) $(INCS) -c $< -o $@

$(NAME) : $(OBJS)
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
	# $(RM) $(OBJS_C)

fclean: clean
	$(RM) $(NAME)
	# $(RM) $(NAME_C)
	$(RM) ./libft/libft.a

re: clean all

.PHONY: all clean fclean re
