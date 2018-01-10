# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spopieul <spopieul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 20:00:07 by bgeorges          #+#    #+#              #
#    Updated: 2018/01/10 13:58:29 by spopieul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
OBJS = ft_main.o ft_print.o ft_algo.o ft_parsing.o ft_parsing_check.o ft_algo_utils.o ft_utils.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
