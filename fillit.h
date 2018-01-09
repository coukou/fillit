/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spopieul <spopieul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:04:15 by bgeorges          #+#    #+#             */
/*   Updated: 2018/01/09 17:21:35 by spopieul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "fillit.h"

# define BUFF_SIZE 4096

typedef struct	s_tetrimino
{
	unsigned long	lines[4];
	int				width;
	int				height;
	int				x;
	int				y;
}				t_tetrimino;

typedef struct	s_map
{
	unsigned long	*lines;
	size_t			size;
}				t_map;

void			ft_get_tetriminos(char *buf, unsigned short *tetriminos);
void			ft_error();
void			ft_start_resolve(unsigned short *tetriminos_tmp);
int				ft_can_insert_tetrimino(t_map *map, t_tetrimino *tetrimino);
t_tetrimino		*ft_init_tetrimino(t_tetrimino *tetrimino, unsigned long data);
int				ft_strlen(char *str);
void			ft_putendl(char *str);
void			ft_print_map(t_map *map, t_tetrimino *tetriminos);
int				ft_is_valid_tetriminos(char *tetriminos);
int				ft_check_line(char *line);

#endif
