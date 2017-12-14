# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 20:00:07 by bgeorges          #+#    #+#              #
#    Updated: 2017/12/14 19:55:39 by bgeorges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = fillit

NAME = libft.a

SRCS = ft_main.c ft_algo.c ft_parsing.c

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint \
	ft_itoa ft_memalloc ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel \
	ft_memmove ft_memset ft_memalloc ft_putchar_fd ft_putchar ft_putendl_fd \
	ft_putendl ft_putnbr_fd ft_putnbr ft_putstr_fd ft_putstr ft_strcat \
	ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdel ft_strdup ft_strequ \
	ft_striter ft_striteri ft_strjoin ft_strlcat ft_strlen ft_strmap \
	ft_strmapi ft_strncat ft_strncmp ft_strncpy ft_strnequ \
	ft_strnew ft_strnstr ft_strrchr ft_strsplit ft_strstr ft_strsub \
	ft_strtrim ft_tolower ft_toupper ft_lstmap ft_lstiter ft_lstadd ft_lstnew \
	ft_lstdel ft_lstdelone

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(addsuffix .c, $(basename $(SRC))) -I libft.h
	ar rc $(NAME) $(addsuffix .o, $(basename $(SRC)))
	ranlib $(NAME)
	gcc -o $(FLAGS) $(SRCS) $(EXEC)
clean:
	/bin/rm -f $(addsuffix .o, $(basename $(SRC)))

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
