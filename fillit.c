/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:56:33 by bgeorges          #+#    #+#             */
/*   Updated: 2017/12/08 16:34:00 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "libft.h"

#define	BUFF_SIZE 4096

void	ft_convert(char *tetriminos, int nb_tetriminos)
{
	int i;
	unsigned short	converted;
	unsigned short	all_converted[26];

	i = 0;
	while(tetriminos[i] != '\0')
	{
		converted = converted  << 1;
		if (tetriminos[i] == '#')
			converted |= 1;
		i++;
	}
	all_converted[nb_tetriminos] = converted;
	printf("%d\n", all_converted[nb_tetriminos]);
}

void	ft_error()
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

void	ft_valid2(char *tetriminos, int nb_tetriminos)
{
	int right;
	int left;
	int top;
	int bottom;
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetriminos[i] != '\0')
	{
		if (tetriminos[i] == '#')
		{
			right = (i + 1) <= 16 ? tetriminos[i + 1] == '#' : 0;
			left = (i - 1) >= 0 ? tetriminos[i - 1] == '#' : 0;
			top = (i - 4) >= 0 ? tetriminos[i - 4] == '#' : 0;
			bottom = (i + 4) <= 16 ? tetriminos[i + 4] == '#' : 0;

		if (right == 0 && left == 0 && top == 0 && bottom == 0)
			ft_error();
		}
		i++;
	}
		ft_convert(tetriminos, nb_tetriminos);
}

int ft_valid1(char *buf)
{
	int i;
	int j;
	int k;
	int nb_tetriminos;
	char tetriminos[16];

	i = 0;
	k = 0;
	nb_tetriminos = 0;
	while (buf[k] != '\0')
	{

		if (i == '\n')
		{
			ft_error();
		}
		j = 0;
		while ((buf[k] == '.' || buf[k] == '#') && buf[k] != '\n')
		{
			tetriminos[i] = buf[k];
			j++;
			k++;
			i++;
		}
		if (j != 4)
		{
			ft_error();
		}
		else
			k++;
		if (i == 16 || buf[k] == '\0')
		{
			tetriminos[i] = '\0';
			ft_valid2(tetriminos, nb_tetriminos);
			nb_tetriminos++;
			if (buf[k] == '\n')
				k++;
			i = 0;
		}
	}
	return(0);
}

void		ft_isvalid(int argc, char **argv)
{
	char buf[BUFF_SIZE + 1];
	int fd;
	int ret;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit tetriminos_list_file");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	ft_valid1(buf);
	}

int main (int ac, char **av)
{
	ft_isvalid(ac, av);
	return (0);
}
