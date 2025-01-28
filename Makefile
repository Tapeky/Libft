# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 14:05:56 by tsadouk           #+#    #+#              #
#    Updated: 2025/01/28 23:18:19 by tsadouk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Werror -Wextra -Iinclude

SRCS =  src/conversion/ft_atoi.c \
	src/conversion/ft_atoi2.c \
	src/conversion/ft_itoa.c \
	src/conversion/ft_tolower.c \
	src/conversion/ft_toupper.c \
	src/is/ft_isalnum.c \
	src/is/ft_isalpha.c \
	src/is/ft_isascii.c \
	src/is/ft_isdigit.c \
	src/is/ft_isprint.c \
	src/is/ft_isspace.c \
	src/list/ft_lstadd_back.c \
	src/list/ft_lstadd_front.c \
	src/list/ft_lstclear.c \
	src/list/ft_lstdelone.c \
	src/list/ft_lstiter.c \
	src/list/ft_lstlast.c \
	src/list/ft_lstmap.c \
	src/list/ft_lstnew.c \
	src/list/ft_lstsize.c \
	src/memory/ft_bzero.c \
	src/memory/ft_calloc.c \
	src/memory/ft_memchr.c \
	src/memory/ft_memcmp.c \
	src/memory/ft_memcpy.c \
	src/memory/ft_memmove.c \
	src/memory/ft_memset.c \
	src/print/ft_putchar_fd.c \
	src/print/ft_putendl_fd.c \
	src/print/ft_putnbr_fd.c \
	src/print/ft_putnbr_base_fd.c \
	src/print/ft_putnchar_fd.c \
	src/print/ft_putstr_fd.c \
	src/string/ft_nbrlen.c \
	src/string/ft_split.c \
	src/string/ft_strchr.c \
	src/string/ft_strdup.c \
	src/string/ft_striteri.c \
	src/string/ft_strjoin.c \
	src/string/ft_strlcat.c \
	src/string/ft_strlcpy.c \
	src/string/ft_strlen.c \
	src/string/ft_strmapi.c \
	src/string/ft_strncmp.c \
	src/string/ft_strnstr.c \
	src/string/ft_strnstr.c \
	src/string/ft_strrchr.c \
	src/string/ft_strtrim.c \
	src/string/ft_substr.c \

OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

NAME = libft.a

# Colors for messages
GREEN = \033[0;32m
RESET = \033[0m

# Default rule
all: $(NAME)

# Library compilation
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)Compilation finished: $(NAME) is ready!$(RESET)"

# Object files compilation
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Cleaning object files
clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(GREEN)All object files have been removed.$(RESET)"

# Full cleanup
fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)The library $(NAME) has been removed.$(RESET)"

# Full recompilation
re: fclean all

.PHONY: clean all re fclean
