# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 14:05:56 by tsadouk           #+#    #+#              #
#    Updated: 2023/11/10 17:03:01 by tsadouk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Werror -Wextra

SRCS =  ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c  \
		ft_atoi.c \
		ft_bzero.c \
		ft_strnstr.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_split.c  \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c  \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \

SRCS_BONUS =  ft_lstsize.c ft_lstnew.c ft_lstmap.c ft_lstlast.c ft_lstiter.c ft_lstdelone.c \
			  ft_lstclear.c ft_lstadd_front.c ft_lstadd_back.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

bonus: $(OBJS_BONUS) $(OBJS)
		ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(OBJS_BONUS) libft.so

re: fclean all

.PHONY: clean all re fclean

