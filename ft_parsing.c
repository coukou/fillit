/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:56:33 by bgeorges          #+#    #+#             */
/*   Updated: 2017/12/18 17:15:16 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFF_SIZE 4096
#include <fcntl.h>
unsigned short	ft_convert(char *tetriminos)
{
	int				i;
	unsigned short	tetriminos_converted;

	i = 15;
	while (tetriminos[i] != '\0')
	{
		tetriminos_converted = tetriminos_converted << 1;
		if (tetriminos[i] == '#')
			tetriminos_converted |= 1;
		i--;
	}
	return (tetriminos_converted);
}

void			ft_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

int				ft_is_valid_tetriminos(char *tetriminos)
{
	int		right;
	int		left;
	int		top;
	int		bottom;
	int		i;

	i = 0;
	while (tetriminos[i] != '\0')
	{
		if (tetriminos[i] == '#')
		{
			right = (i + 1) <= 16 ? tetriminos[i + 1] == '#' : 0;
			left = (i - 1) >= 0 ? tetriminos[i - 1] == '#' : 0;
			top = (i - 4) >= 0 ? tetriminos[i - 4] == '#' : 0;
			bottom = (i + 4) <= 16 ? tetriminos[i + 4] == '#' : 0;
			if (right == 0 && left == 0 && top == 0 && bottom == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

void			ft_get_tetriminos(char *buf, unsigned short *tetriminos)
{
	int				i;
	int				j;
	char			tmp[17];
	int				nb_tetriminos;

	i = 0;
	nb_tetriminos = 0;
	while (*buf != '\0')
	{
		j = 0;
		while (*buf && (*buf == '.' || *buf == '#') && j < 4)
		{
			tmp[i++] = *buf++;
			j++;
		}
		if (*buf != '\n')
			ft_error();
		if (i == 16)
		{
			tmp[i] = '\0';
			tetriminos[nb_tetriminos++] = ft_convert(tmp);
			if (*buf == '\n')
				buf++;
			i = 0;
		}
		if (*buf != '\n' && *buf != '\0')
			ft_error();
		else
			buf++;
		if (*buf == '\n')
			ft_error();
	}
	tetriminos[nb_tetriminos] = 0;
}

int     main(int ac, char **av)
{
    char			buf[BUFF_SIZE + 1];
    int				fd;
    int				ret;
    unsigned short	tetriminos[26];


    if (ac != 2)
    {
        ft_putendl("usage: ./fillit tetriminos_list_file");
        exit(EXIT_FAILURE);
    }
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        ft_error();
    ret = read(fd, buf, BUFF_SIZE);
    buf[ret] = '\0';
    if (((buf[ret - 2] == '#' || buf[ret - 2] == '.') && buf[ret - 1] == '\n') || *buf == '\0')
        ft_get_tetriminos(buf, tetriminos);
    else
		ft_error();
	return (0);
}
