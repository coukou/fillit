/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spopieul <spopieul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:04:15 by bgeorges          #+#    #+#             */
/*   Updated: 2017/12/18 22:39:41 by spopieul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

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

void    ft_get_tetriminos(char *buf, unsigned short *tetriminos);
void    ft_error();
void	ft_start_resolve(unsigned short *tetriminos_tmp);

/*
	a ajouter

	ft_reset_tetrimino
	ft_can_insert_tetrimino
	ft_init_tetrimino
	ft_putendl
*/

#endif
