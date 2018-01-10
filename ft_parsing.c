/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spopieul <spopieul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:56:33 by bgeorges          #+#    #+#             */
/*   Updated: 2018/01/10 14:20:17 by spopieul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short		ft_convert(char *tetriminos)
{
	int				i;
	unsigned short	tetriminos_converted;

	i = 15;
	while (i >= 0)
	{
		tetriminos_converted = tetriminos_converted << 1;
		if (tetriminos[i] == '#')
			tetriminos_converted |= 1;
		i--;
	}
	return (tetriminos_converted);
}

unsigned short		ft_create_tetrimino(char *tmp, int hash_count)
{
	if (hash_count != 4)
		ft_error();
	if (!ft_is_valid_tetriminos(tmp))
		ft_error();
	return (ft_convert(tmp));
}

int					ft_get_line(char *buf, char (*line)[])
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		(*line)[i] = buf[i];
		i++;
	}
	return (0);
}

unsigned short		ft_parse_tetrimino(char *tmp)
{
	if (!ft_is_valid_tetriminos(tmp))
		ft_error();
	return (ft_convert(tmp));
}

void				ft_get_tetriminos(char *buf, unsigned short *tetriminos)
{
	char	line[4096];
	char	tmp[17];
	int		i;
	int		nb_tetriminos;

	i = 0;
	nb_tetriminos = 0;
	tmp[16] = 0;
	while (ft_get_line(buf, &line))
	{
		if ((i != 4 && !ft_check_line(line)) || (i == 4 && *line != '\0'))
			ft_error();
		if (i != 4)
			ft_strncpy(&tmp[(i++) * 4], line, 4);
		else
		{
			tetriminos[nb_tetriminos++] = ft_parse_tetrimino(tmp);
			i = 0;
		}
		buf += ft_strlen(line) + 1;
		ft_bzero(&line, 4096);
	}
	if (i != 4)
		ft_error();
	tetriminos[nb_tetriminos++] = ft_parse_tetrimino(tmp);
}
