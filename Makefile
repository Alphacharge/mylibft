# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 14:21:20 by rbetz             #+#    #+#              #
#    Updated: 2022/09/19 11:33:55 by rbetz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
		ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
		ft_atol.c ft_ltoa.c ft_strstr.c ft_strreplace.c ft_strisdigit.c \
		ft_printf.c ft_printflibft.c \
		get_next_line_bonus.c get_next_line_utils_bonus.c \
		ft_first_word.c

SRCOBJ=$(SRC:.c=.o)

CC = "cc"
CFLAGS = -Wall -Wextra -Werror

RED = \033[1;31m
GREEN = \033[1;32m
YELL = \033[1;33m
BLUE = \033[1;34m
WHITE = \033[0m

all: $(NAME)

$(NAME): $(SRCOBJ)
	@ar -rucs $(NAME) $^
	@echo "$(RED)--->$(BLUE)Libft is compiled.$(WHITE)"

clean:
	@echo "$(RED)Cleaning Objects:\n$(WHITE)$(SRCOBJ)"
	@/bin/rm -f $(SRCOBJ) libft.h.gch

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		/bin/rm -f $(NAME); \
		echo "$(YELL)Cleaning Lib:\n$(WHITE)$(NAME)";else \
		echo "No $(NAME) to remove."; \
	fi;

re: fclean all

.PHONY: all clean fclean re