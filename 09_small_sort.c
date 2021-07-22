/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:21:44 by ulee              #+#    #+#             */
/*   Updated: 2021/07/22 23:40:21 by ulee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort_a(t_info *io, int size)
{
	if (size == 3)
		small_sort_3_a(io);
	else if (size == 2)
	{
		if (io->a->size >= 2 && io->a->top->data
			> io->a->top->next->data)
		{
			if (io->b->size >= 2 && io->b->top->data
				< io->b->top->next->data)
				command(io, "ss");
			else
				command(io, "sa");
		}
	}
}

void	small_sort_b(t_info *io, int size)
{
	if (size == 3)
		small_sort_3_b(io);
	else
	{
		if (size == 2)
		{
			if (io->b->size >= 2 && io->b->top->data
				< io->b->top->next->data)
			{
				if (io->a->size >= 2 && io->a->top->data
					> io->a->top->next->data)
					command(io, "ss");
				else
					command(io, "sb");
			}
			command(io, "pa");
		}
		command(io, "pa");
	}
}
