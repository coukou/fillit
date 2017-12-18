/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spopieul <spopieul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:23:06 by spopieul          #+#    #+#             */
/*   Updated: 2017/12/18 22:28:13 by spopieul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl(char *str)
{
	size_t		len;
	char		back_slash_n;

	len = 0;
	back_slash_n = '\n';
	while (str[len])
		len++;
	write(1, str, len);
	write(1, &back_slash_n, 1);
}

void	ft_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}
