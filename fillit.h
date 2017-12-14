/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:04:15 by bgeorges          #+#    #+#             */
/*   Updated: 2017/12/14 19:56:00 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "fillit.h"
#define BUFF_SIZE 4096

typedef struct	s_tetrimino
{
	unsigned long	lines[4];
	int				width;
	int				height;
	int				x;
	int				y;
}	t_tetrimino;

typedef struct	s_map
{
	unsigned long	*lines;
	size_t			size;
}	t_map;

void    ft_get_tetriminos(buf, tetriminos);
void    ft_error();
