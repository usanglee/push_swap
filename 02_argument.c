/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:21:25 by ulee              #+#    #+#             */
/*   Updated: 2021/07/22 23:33:54 by ulee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ac_2(t_info *io, char *av)
{
	int		i;

	i = 0;
	io->split = ft_split(av, ' ');
	i = 0;
	while (io->split[i])
		i++;
	io->len_arg = i;
}

void	ac_many(t_info *io, int len, char **av)
{
	int		i;

	io->split = (char **)malloc(sizeof(char *) * (len + 1));
	io->split[len] = NULL;
	i = 0;
	while (av[i])
	{
		io->split[i] = ft_strdup(av[i]);
		i++;
	}
	io->len_arg = len;
}
