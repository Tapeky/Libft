# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomoron <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 00:35:01 by tomoron           #+#    #+#              #
#    Updated: 2023/12/04 09:50:41 by tomoron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

SRCS =			ft_atoi.c\
				ft_bzero.c\
				ft_calloc.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoa.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memset.c\
				ft_putchar_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_putstr_fd.c\
				ft_split.c\
				ft_strchr.c\
				ft_strdup.c\
				ft_striteri.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strmapi.c\
				ft_strcmp.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strtrim.c\
				ft_substr.c\
				ft_tolower.c\
				ft_toupper.c\
				ft_split_set.c

SRCS_BONUS =	ft_lstnew.c\
				ft_lstadd_front.c\
				ft_lstsize.c\
				ft_lstlast.c\
				ft_lstadd_back.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c\

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)


$(NAME): ft_printf $(OBJS)
	make --no-print-directory -C ./ft_printf
	cp ./ft_printf/libftprintf.a ./gnl/gnl.a
	make --no-print-directory -C ./gnl
	cp ./gnl/gnl.a ./$(NAME)
	ar rcs $(NAME) $(OBJS)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

bonus: $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make --no-print-directory -C ./ft_printf fclean
	make --no-print-directory -C ./gnl fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(FLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(OBJS_BONUS)


.PHONY: bonus so clean all re fclean
