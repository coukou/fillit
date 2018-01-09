/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spopieul <spopieul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:23:06 by spopieul          #+#    #+#             */
/*   Updated: 2018/01/09 16:14:42 by spopieul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putendl(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	ft_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}
