/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spopieul <spopieul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:31:05 by spopieul          #+#    #+#             */
/*   Updated: 2018/01/10 16:01:11 by spopieul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_get_tetrimino_height(t_tetrimino *tetrimino)
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

size_t			ft_get_tetrimino_width(t_tetrimino *tetrimino)
{
	int i;
	int j;
	int width;
	int width_tmp;

	i = -1;
	width = 0;
	while (++i < 4)
	{
		width_tmp = 0;
		j = -1;
		while (++j < 4)
			if ((tetrimino->lines[i] >> j) & 1)
				width_tmp = j + 1;
		if (width_tmp > width)
			width = width_tmp;
	}
	return (width);
}

t_tetrimino		*ft_init_tetrimino(t_tetrimino *tetrimino, unsigned long data)
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
	while (tetrimino->lines[0] == 0)
	{
		i = -1;
		while (++i < 3)
			tetrimino->lines[i] = tetrimino->lines[1 + i];
		tetrimino->lines[3] = 0;
	}
	tetrimino->width = ft_get_tetrimino_width(tetrimino);
	tetrimino->height = ft_get_tetrimino_height(tetrimino);
	tetrimino->x = 0;
	tetrimino->y = 0;
	return (tetrimino);
}

int				ft_can_insert_tetrimino(t_map *map, t_tetrimino *tetrimino)
{
	int				i;
	unsigned long	tetri_line;
	unsigned long	map_line;

	i = -1;
	while (++i < 4)
	{
		tetri_line = (tetrimino->lines[i] << tetrimino->x);
		map_line = map->lines[tetrimino->y + i];
		if ((map_line + tetri_line) > (map_line ^ tetri_line))
			return (0);
	}
	return (1);
}
