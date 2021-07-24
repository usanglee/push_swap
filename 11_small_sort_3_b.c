/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_small_sort_3_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:21:53 by ulee              #+#    #+#             */
/*   Updated: 2021/07/25 00:19:51 by ulee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_pa(t_info *io)
{
	command(io, "pa");
	command(io, "pa");
	command(io, "pa");
}

void	small_sort_123_b(t_info *io)
{
	if (io->b->size == 3)
	{
		command(io, "sb");
		command(io, "rrb");
		command(io, "pa");
		command(io, "pa");
		command(io, "pa");
	}
	else
	{
		command(io, "rb");
		command(io, "sb");
		command(io, "pa");
		command(io, "pa");
		command(io, "rrb");
		command(io, "pa");
	}
}

void	small_sort_213_b(t_info *io)
{
	if (io->b->size == 3)
	{
		command(io, "rrb");
		command(io, "pa");
		command(io, "pa");
		command(io, "pa");
	}
	else
	{
		command(io, "pa");
		command(io, "sb");
		command(io, "pa");
		command(io, "sa");
		command(io, "pa");
	}
}

void	small_sort_132_b(t_info *io)
{
	if (io->b->size == 3)
	{
		command(io, "rb");
		command(io, "pa");
		command(io, "pa");
		command(io, "pa");
	}
	else
	{
		command(io, "sb");
		command(io, "pa");
		command(io, "sb");
		command(io, "pa");
		command(io, "pa");
	}
}

void	small_sort_3_b(t_info *io)
{
	int	data[3];

	data[0] = io->b->top->data;
	data[1] = io->b->top->next->data;
	data[2] = io->b->top->next->next->data;
	if (data[0] < data[1] && data[0] < data[2] && data[1] < data[2])
		small_sort_123_b(io);
	else if (data[0] < data[1] && data[0] < data[2] && data[1] > data[2])
		small_sort_132_b(io);
	else if (data[0] > data[1] && data[0] < data[2] && data[1] < data[2])
		small_sort_213_b(io);
	else if (data[0] < data[1] && data[0] > data[2] && data[1] > data[2])
	{
		command(io, "sb");
		three_pa(io);
	}
	else if (data[0] > data[1] && data[0] > data[2] && data[1] < data[2])
	{
		three_pa(io);
		command(io, "sa");
	}
	else
		three_pa(io);
}
