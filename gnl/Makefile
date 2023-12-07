# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomoron <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 08:03:00 by tomoron           #+#    #+#              #
#    Updated: 2023/12/04 09:49:24 by tomoron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

CC = gcc

SRCS =	get_next_line_bonus.c\
		get_next_line_utils_bonus.c
		
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

bonus: all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus clean all re fclean
