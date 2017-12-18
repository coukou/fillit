/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spopieul <spopieul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:00:30 by bgeorges          #+#    #+#             */
/*   Updated: 2017/12/18 20:36:39 by spopieul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     main(int ac, char **av)
{
    char			buf[BUFF_SIZE + 1];
    int				fd;
    int				ret;
    unsigned short	tetriminos[27];


    if (ac != 2)
    {
        ft_putendl("usage: ./fillit tetriminos_list_file");
        exit(EXIT_FAILURE);
    }
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        ft_error();
    ret = read(fd, buf, BUFF_SIZE);
    buf[ret] = '\0';
    if (buf[ret - 1] == '\n' && buf[ret - 2] == '\n')
        ft_error();
    if ((buf[ret - 2] == '#' || buf[ret - 2] == '.') || *buf != '\0')
        ft_get_tetriminos(buf, tetriminos);
    else
        ft_error();
    ft_start_resolve(tetriminos);
}
