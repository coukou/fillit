/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:03:35 by spopieul          #+#    #+#             */
/*   Updated: 2017/12/14 19:56:09 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			get_tetrimino_height(t_tetrimino *tetrimino)
{
	int i;
	int height;

	i = -1;
	height = 0;
	while (++i < 4)
	{
		if (tetrimino->lines[i] > 0)
			height++;
	}
	return (height);
}

size_t			get_tetrimino_width(t_tetrimino *tetrimino)
{
	int i;
	int j;
	int width;

	i = -1;
	width = 0;
	while (++i < 4)
	{
		j = 0;
		while ((tetrimino->lines[i] >> j) & 1 && j < 4)
			j++;
		if (j > width)
			width = j;
	}
	return (width);
}

t_tetrimino		*reset_tetrimino(t_tetrimino *tetrimino)
{
	tetrimino->x = 0;
	tetrimino->y = 0;
	return (tetrimino);
}

t_tetrimino		*init_tetrimino(t_tetrimino *tetrimino, unsigned long data)
{
	int i;

	i = -1;
	while (++i < 4)
		tetrimino->lines[i] = (data >> (i * 4)) & 0xf;
	while (!(tetrimino->lines[0] & 1) && !(tetrimino->lines[1] & 1)
			&& !(tetrimino->lines[2] & 1) && !(tetrimino->lines[3] & 1))
	{
		i = -1;
		while (++i < 4)
			tetrimino->lines[i] = tetrimino->lines[i] >> 1;
	}
	tetrimino->width = get_tetrimino_width(tetrimino);
	tetrimino->height = get_tetrimino_height(tetrimino);
	reset_tetrimino(tetrimino);
	return (tetrimino);
}

int		insert_tetrimino(t_map *map, t_tetrimino *tetrimino)
{
	int i;
	unsigned long tetri_line;
	unsigned long map_line;

	i = -1;
	while (++i < 4)
	{
		tetri_line = (tetrimino->lines[i] << tetrimino->x);
		map_line = map->lines[tetrimino->y + i];
		if ((map_line + tetri_line) > (map_line ^ tetri_line))
			return (0);
		map->lines[tetrimino->y + i] = (map_line ^ tetri_line);
	}

	return (1);
}

int		resolve(t_map *map, t_tetrimino *tetriminos, int i)
{
	t_tetrimino *t;

	t = &tetriminos[i];
	if (t->width == 0 || t->height == 0 || i == 26)
		return (1);
	reset_tetrimino(t);
	while (t->y + t->height <= map->size)
	{
		t->x = 0;
		while (t->x + t->width <= map->size)
		{
			if (insert_tetrimino(map, t))
			{
				if (resolve(map, tetriminos, i + 1))
					return (1);
				insert_tetrimino(map, t);
			}
			t->x++;
		}
		t->y++;
	}
	return (0);
}

void	print_map(t_map *map, t_tetrimino *tetriminos)
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
	while ((t = &tetriminos[++i])->width && i < 26)
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
		printf("%s\n", char_map[i]);
}

void	start_resolve(t_tetrimino *tetriminos, size_t map_size)
{
	t_map map;
	unsigned long lines[map_size];

	map.lines = lines;
	map.size = map_size;
	while (map_size)
		map.lines[--map_size] = 0;
	if (!resolve(&map, tetriminos, 0))
		return start_resolve(tetriminos, map.size + 1);
	print_map(&map, tetriminos);
}
