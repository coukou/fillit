/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spopieul <spopieul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:16:30 by spopieul          #+#    #+#             */
/*   Updated: 2018/01/09 17:20:43 by spopieul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_horizontal_sum(char *tetriminos, int i)
{
	int right;
	int left;

	right = (i + 1) <= 16 ? tetriminos[i + 1] == '#' : 0;
	left = (i - 1) >= 0 ? tetriminos[i - 1] == '#' : 0;
	return (right + left);
}

int		ft_vertical_sum(char *tetriminos, int i)
{
	int top;
	int bottom;

	top = (i - 4) >= 0 ? tetriminos[i - 4] == '#' : 0;
	bottom = (i + 4) <= 16 ? tetriminos[i + 4] == '#' : 0;
	return (top + bottom);
}

int		ft_is_valid_tetriminos(char *tetriminos)
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
			hash_count++;
			sum += ft_vertical_sum(tetriminos, i);
			sum += ft_horizontal_sum(tetriminos, i);
		}
		i++;
	}
	if (hash_count != 4)
		return (0);
	return (sum >= 6);
}

int		ft_check_line(char *line)
{
	if (ft_strlen(line) != 4)
		return (0);
	while (*line)
	{
		if (*line != '.' && *line != '#')
			return (0);
		line++;
	}
	return (1);
}
