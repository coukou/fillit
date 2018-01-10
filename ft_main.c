/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spopieul <spopieul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:15:22 by spopieul          #+#    #+#             */
/*   Updated: 2018/01/10 13:23:24 by spopieul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	char			buf[BUFF_SIZE + 1];
	int				fd;
	int				ret;
	unsigned short	tetriminos[27];

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit tetriminos_description_file");
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	ft_get_tetriminos(buf, tetriminos);
	ft_start_resolve(tetriminos);
}
