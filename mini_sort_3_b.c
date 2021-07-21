/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_3_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:56:29 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/22 18:34:28 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort_123_b(t_info *io)
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

void	mini_sort_213_b(t_info *io)
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

void	mini_sort_132_b(t_info *io)
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

void	mini_sort_3_b(t_info *io)
{
	int	rank[3];

	rank[0] = io->b->top->data;
	rank[1] = io->b->top->next->data;
	rank[2] = io->b->top->next->next->data;
	if (rank[0] < rank[1] && rank[0] < rank[2] && rank[1] < rank[2])
		mini_sort_123_b(io);
	else if (rank[0] < rank[1] && rank[0] < rank[2] && rank[1] > rank[2])
		mini_sort_132_b(io);
	else if (rank[0] > rank[1] && rank[0] < rank[2] && rank[1] < rank[2])
		mini_sort_213_b(io);
	else if (rank[0] < rank[1] && rank[0] > rank[2] && rank[1] > rank[2])
	{
		command(io, "sb");
		command(io, "pa");
		command(io, "pa");
		command(io, "pa");
	}
	else if (rank[0] > rank[1] && rank[0] > rank[2] && rank[1] < rank[2])
	{
		command(io, "pa");
		command(io, "pa");
		command(io, "pa");
		command(io, "sa");
	}
	else
	{
		command(io, "pa");
		command(io, "pa");
		command(io, "pa");
	}
}
