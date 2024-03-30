# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 14:05:56 by tsadouk           #+#    #+#              #
#    Updated: 2024/03/22 15:09:32 by tsadouk          ###   ########.fr        #
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
        ft_isspace.c \
        ft_atoi2.c \
        ft_nbrlen.c \
        ft_isspace.c \
		ft_putnchar_fd.c \
		ft_putnbr_base_fd.c \
		ft_putchar_fd.c \
		ft_lstsize.c ft_lstnew.c ft_lstmap.c ft_lstlast.c ft_lstiter.c ft_lstdelone.c \
        ft_lstclear.c ft_lstadd_front.c ft_lstadd_back.c

OBJS_DIR = obj

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJS_DIR)/, $(SRCS_BONUS:.c=.o))

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS_BONUS) $(OBJS)
	ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME) libft.so

re: fclean all

.PHONY: clean all re fclean bonus


