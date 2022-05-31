# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 13:46:08 by rbetz             #+#    #+#              #
#    Updated: 2022/05/31 17:55:11 by rbetz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = "libft.a"
SRC = libft/*.c libft/*.h printf/*.c printf/*.h get_next_line/*.c get_next_line/*.h
SRCOBJ=$(SRC:.c=.o)
CC = "cc"
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCOBJ)
	ar -rcs $(NAME) $^

clean:
	/bin/rm -f $(SRCOBJ) libft.h.gch

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
