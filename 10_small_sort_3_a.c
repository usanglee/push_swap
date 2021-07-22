/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_small_sort_3_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:21:47 by ulee              #+#    #+#             */
/*   Updated: 2021/07/22 23:40:30 by ulee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort_132_a(t_info *io)
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

void	small_sort_231_a(t_info *io)
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

void	small_sort_312_a(t_info *io)
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

void	small_sort_321_a(t_info *io)
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

void	small_sort_3_a(t_info *io)
{
	int	data[3];

	data[0] = io->a->top->data;
	data[1] = io->a->top->next->data;
	data[2] = io->a->top->next->next->data;
	if (data[0] < data[1] && data[0] < data[2] && data[1] < data[2])
		return ;
	else if (data[0] > data[1] && data[0] < data[2] && data[1] < data[2])
		command(io, "sa");
	else if (data[0] < data[1] && data[0] < data[2] && data[1] > data[2])
		small_sort_132_a(io);
	else if (data[0] < data[1] && data[0] > data[2] && data[1] > data[2])
		small_sort_231_a(io);
	else if (data[0] > data[1] && data[0] > data[2] && data[1] < data[2])
		small_sort_312_a(io);
	else
		small_sort_321_a(io);
}
