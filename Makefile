# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spopieul <spopieul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 20:00:07 by bgeorges          #+#    #+#              #
#    Updated: 2018/01/09 17:21:00 by spopieul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
SRCS = ft_main.c ft_print.c ft_algo.c ft_parsing.c ft_parsing_check.c ft_algo_utils.c ft_utils.c
FLAGS = -ggdb -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	@echo "on a rien a clean"

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
