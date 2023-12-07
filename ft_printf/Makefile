# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomoron <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 08:03:00 by tomoron           #+#    #+#              #
#    Updated: 2023/11/15 14:42:45 by tomoron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

SRCS =	ft_protected_atoi.c\
		ft_convert.c\
		ft_isdigit.c\
		ft_parse_arg.c\
		ft_print_hex_ptr.c\
		ft_print_int.c\
		ft_print_unsigned_int.c\
		ft_printf.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_strlen.c\
		ft_write_str_part.c
		
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
