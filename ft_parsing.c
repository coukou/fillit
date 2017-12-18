/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spopieul <spopieul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:56:33 by bgeorges          #+#    #+#             */
/*   Updated: 2017/12/18 22:40:24 by spopieul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int				ft_horizontal_sum(char *tetriminos, int i)
{
	int right;
	int left;

	right = (i + 1) <= 16 ? tetriminos[i + 1] == '#' : 0;
	left = (i - 1) >= 0 ? tetriminos[i - 1] == '#' : 0;
	return (right + left);
}

int				ft_vertical_sum(char *tetriminos, int i)
{
	int top;
	int bottom;

	top = (i - 4) >= 0 ? tetriminos[i - 4] == '#' : 0;
	bottom = (i + 4) <= 16 ? tetriminos[i + 4] == '#' : 0;
	return (top + bottom);
}

int				ft_is_valid_tetriminos(char *tetriminos)
{
	int		i;
	int		hash_count;
	int		sum;

	i = 0;
	hash_count = 0;
	sum = 0;
	while (tetriminos[i] != '\0')
	{
		if (tetriminos[i] == '#')
		{
			sum += ft_vertical_sum(tetriminos, i);
			sum += ft_horizontal_sum(tetriminos, i);
		}
		i++;
	}
	return (sum >= 6);
}

void			ft_get_tetriminos(char *buf, unsigned short *tetriminos)
{
	int				i;
	int				j;
	char			tmp[17];
	int				nb_tetriminos;
	int				hash_count;

	i = 0;
	nb_tetriminos = 0;
	hash_count = 0;
	while (*buf != '\0')
	{
		j = 0;
		while (*buf && (*buf == '.' || *buf == '#') && j < 4)
		{
			if (*buf == '#')
				hash_count++;
			tmp[i++] = *buf++;
			j++;
		}
		if (*buf != '\n')
			ft_error();
		if (i == 16)
		{
			if (hash_count != 4)
				ft_error();
			if (!ft_is_valid_tetriminos(tmp))
				ft_error();
			hash_count = 0;
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
	if (i != 0)
		ft_error();
	tetriminos[nb_tetriminos] = 0;
}
