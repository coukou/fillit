/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:56:33 by bgeorges          #+#    #+#             */
/*   Updated: 2017/12/14 19:44:43 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned short	ft_convert(char *tetriminos)
{
	int				i;
	unsigned short	tetriminos_converted;

	i = 0;
	while (tetriminos[i] != '\0')
	{
		tetriminos_converted = tetriminos_converted << 1;
		if (tetriminos[i] == '#')
			tetriminos_converted |= 1;
		i++;
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

void			ft_get_next_tetriminos
	(char *tmp, char *buf, unsigned short *tetriminos, int nb_tetriminos)
{
	{
		if (!ft_is_valid_tetriminos(tmp))
			ft_error();
		tetriminos[nb_tetriminos++] = ft_convert(tmp);
		buf++;
	}
}

void			ft_get_tetriminos(char *buf, unsigned short *tetriminos)
{
	int				i;
	int				j;
	char			tmp[16];
	int				nb_tetriminos;

	i = 0;
	nb_tetriminos = 0;
	while (*buf != '\0')
	{
		j = 0;
		while (*buf && (*buf == '.' || *buf == '#'))
		{
			tmp[i++] = *buf++;
			j++;
		}
		if (j != 4 && *buf != '\n')
			ft_error();
		if (i == 16)
		{
			tmp[i] = '\0';
			ft_get_next_tetriminos(tmp, buf, tetriminos, nb_tetriminos);
			i = 0;
		}
		if ((*buf != '\n' && *buf != '\0') || (nb_tetriminos > 26))
			ft_error();
		else
			buf++;
	}
	tetriminos[nb_tetriminos] = 0;
}

int	main(void)
{
	return (0);
}
