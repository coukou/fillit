/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spopieul <spopieul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:10:32 by spopieul          #+#    #+#             */
/*   Updated: 2018/01/10 14:47:13 by spopieul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_init_char_map(char char_map[256][256], size_t map_size)
{
	int x;
	int y;

	y = -1;
	while (++y < (int)map_size)
	{
		x = -1;
		while (++x < (int)map_size)
			char_map[y][x] = '.';
		char_map[y][x] = '\0';
	}
}

void	ft_tetriminos_to_char_map
	(t_tetrimino *tetriminos, char char_map[256][256])
{
	int				i;
	int				x;
	int				y;
	t_tetrimino		*t;

	i = -1;
	while ((t = &tetriminos[++i]) && t->lines[0] != 0 && i < 26)
	{
		y = -1;
		while (++y < 4)
		{
			x = -1;
			while (++x < 4)
			{
				if ((t->lines[y] >> x) & 1)
					char_map[t->y + y][t->x + x] = 'A' + i;
			}
		}
	}
}

void	ft_print_char_map(char char_map[256][256], size_t map_size)
{
	int i;

	i = -1;
	while (++i < (int)map_size)
		ft_putendl(char_map[i]);
}

void	ft_print_map(t_map *map, t_tetrimino *tetriminos)
{
	char char_map[256][256];

	ft_init_char_map(char_map, map->size);
	ft_tetriminos_to_char_map(tetriminos, char_map);
	ft_print_char_map(char_map, map->size);
}
