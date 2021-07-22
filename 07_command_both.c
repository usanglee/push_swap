/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_command_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:21:37 by ulee              #+#    #+#             */
/*   Updated: 2021/07/22 23:21:38 by ulee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_info *io, int c)
{
	swap(io->a, ' ');
	swap(io->b, ' ');
	if (c == 1)
		ft_printf("ss\n");
}

void	rotate_both(t_info *io, int c)
{
	rotate(io->a, ' ');
	rotate(io->b, ' ');
	if (c == 1)
		ft_printf("rr\n");
}

void	reverse_both(t_info *io, int c)
{
	reverse(io->a, ' ');
	reverse(io->b, ' ');
	if (c == 1)
		ft_printf("rrr\n");
}
