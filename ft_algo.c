/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spopieul <spopieul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:03:35 by spopieul          #+#    #+#             */
/*   Updated: 2017/12/18 22:38:42 by spopieul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_insert_tetrimino(t_map *map, t_tetrimino *tetrimino)
{
	int i;
	unsigned long tetri_line;
	unsigned long map_line;

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
	int res = 50;

	t = &tetriminos[i];
	if (t->lines[0] == 0 || i == 26)
		return (1);
	ft_reset_tetrimino(t);
	while (t->y + t->height <= map->size)
	{
		t->x = 0;
		while (t->x + t->width <= map->size)
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
	return (0);
}

// ca faut lui casser sa mere en 2
void	ft_print_map(t_map *map, t_tetrimino *tetriminos)
{
	int i;
	int x;
	int y;
	t_tetrimino *t;
	char	char_map[map->size + 1][map->size + 1];

	y = -1;
	while (++y < map->size)
	{
		x = -1;
		while (++x < map->size)
			char_map[y][x] = '.';
		char_map[y][x] = '\0';
	}
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
	i = -1;
	while (++i < map->size)
		ft_putendl(char_map[i]);
}

void	ft_start_resolve(t_tetrimino *tetriminos, size_t map_size)
{
	t_map map;
	int i;
	unsigned long lines[map_size];

	map.lines = lines;
	map.size = map_size;
	i = -1;
	while (++i < map_size)
		map.lines[i] = 0;
	if (!ft_resolve(&map, tetriminos, 0))
		return ft_start_resolve(tetriminos, map.size + 1);
	ft_print_map(&map, tetriminos);
}

void	ft_bootstrap_resolve(unsigned short *tetriminos_tmp)
{
	int i;
	t_tetrimino tetriminos[26];

	i = -1;
	while (tetriminos_tmp[++i])
		ft_init_tetrimino(&tetriminos[i], tetriminos_tmp[i]);
	tetriminos[i].lines[0] = 0;
	ft_start_resolve(tetriminos, 2);
}
