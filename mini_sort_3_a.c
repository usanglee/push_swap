/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_3_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:46:05 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/21 15:21:32 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort_132_a(t_info *io)
{
	if (io->a->size == 3)
	{
		command(io, "sa");
		command(io, "ra");
	}
	else
	{
		command(io, "pb");
		command(io, "sa");
		command(io, "pa");
	}
}

void	mini_sort_231_a(t_info *io)
{
	if (io->a->size == 3)
	{
		command(io, "rra");
	}
	else
	{
		command(io, "pb");
		command(io, "sa");
		command(io, "pa");
		command(io, "sa");
	}
}

void	mini_sort_312_a(t_info *io)
{
	if (io->a->size == 3)
		command(io, "ra");
	else
	{
		command(io, "sa");
		command(io, "pb");
		command(io, "sa");
		command(io, "pa");
	}
}

void	mini_sort_321_a(t_info *io)
{
	if (io->a->size == 3)
	{
		command(io, "ra");
		command(io, "sa");
	}
	else
	{
		command(io, "sa");
		command(io, "pb");
		command(io, "sa");
		command(io, "pa");
		command(io, "sa");
	}
}

void	mini_sort_3_a(t_info *io)
{
	int	rank[3];

	rank[0] = io->a->top->data;
	rank[1] = io->a->top->next->data;
	rank[2] = io->a->top->next->next->data;
	if (rank[0] < rank[1] && rank[0] < rank[2] && rank[1] < rank[2])
		return ;
	else if (rank[0] > rank[1] && rank[0] < rank[2] && rank[1] < rank[2])
		command(io, "sa");
	else if (rank[0] < rank[1] && rank[0] < rank[2] && rank[1] > rank[2])
		mini_sort_132_a(io);
	else if (rank[0] < rank[1] && rank[0] > rank[2] && rank[1] > rank[2])
		mini_sort_231_a(io);
	else if (rank[0] > rank[1] && rank[0] > rank[2] && rank[1] < rank[2])
		mini_sort_312_a(io);
	else
		mini_sort_321_a(io);
}
