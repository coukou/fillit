/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spopieul <spopieul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:03:35 by spopieul          #+#    #+#             */
/*   Updated: 2018/01/09 15:13:53 by spopieul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_insert_tetrimino(t_map *map, t_tetrimino *tetrimino)
{
	int				i;
	unsigned long	tetri_line;
	unsigned long	map_line;

	i = -1;
	while (++i < 4)
	{
		tetri_line = (tetrimino->lines[i] << tetrimino->x);
		map_line = map->lines[tetrimino->y + i];
		map->lines[tetrimino->y + i] = (map_line ^ tetri_line);
	}
}

int		ft_resolve(t_map *map, t_tetrimino *tetriminos, int i)
{
	t_tetrimino *t;

	t = &tetriminos[i];
	if (t->lines[0] == 0 || i == 26)
		return (1);
	while (t->y + t->height <= (int)map->size)
	{
		t->x = 0;
		while (t->x + t->width <= (int)map->size)
		{
			if (ft_can_insert_tetrimino(map, t))
			{
				ft_insert_tetrimino(map, t);
				if (ft_resolve(map, tetriminos, i + 1))
					return (1);
				ft_insert_tetrimino(map, t);
			}
			t->x++;
		}
		t->y++;
	}
	t->y = 0;
	t->x = 0;
	return (0);
}

void	ft_map_resolve(t_tetrimino *tetriminos, size_t map_size)
{
	t_map			map;
	int				i;
	unsigned long	lines[map_size];

	map.lines = lines;
	map.size = map_size;
	i = -1;
	while (++i < (int)map_size)
		map.lines[i] = 0;
	if (!ft_resolve(&map, tetriminos, 0))
		return (ft_map_resolve(tetriminos, map.size + 1));
	ft_print_map(&map, tetriminos);
}

void	ft_start_resolve(unsigned short *tetriminos_tmp)
{
	int			i;
	t_tetrimino	tetriminos[26];

	i = -1;
	while (tetriminos_tmp[++i])
		ft_init_tetrimino(&tetriminos[i], tetriminos_tmp[i]);
	tetriminos[i].lines[0] = 0;
	ft_map_resolve(tetriminos, 2);
}
