/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:21:41 by ulee              #+#    #+#             */
/*   Updated: 2021/07/24 19:03:23 by ulee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_solve(t_solve *sol, t_deque *deq, int size)
{
	int		*arr;

	arr = make_arr(deq, size);
	quick_sort(arr, 0, size - 1);
	sol->pivot1 = arr[(size - 1) / 3];
	sol->pivot2 = arr[(size - 1) / 3 * 2];
	sol->pa = 0;
	sol->pb = 0;
	sol->ra = 0;
	sol->rb = 0;
	free(arr);
}

void	set_rrr_count(t_info *io, int *ra, int *rb, int *rrr)
{
	if (*ra != 0)
		*ra = *ra % io->a->size;
	if (*rb != 0)
		*rb = *rb % io->b->size;
	if (*ra < *rb)
		*rrr = *ra;
	else
		*rrr = *rb;
	*ra -= *rrr;
	*rb -= *rrr;
}

void	raise_rotate(t_info *io, int ra_size, int rb_size)
{
	int	rrr;

	set_rrr_count(io, &ra_size, &rb_size, &rrr);
	if (io->a->size / 2 < ra_size && io->b->size / 2 < rb_size)
	{
		ra_size = io->a->size - ra_size;
		rb_size = io->b->size - rb_size;
		while (rrr--)
			command(io, "rr");
		while (ra_size-- > 0)
			command(io, "ra");
		while (rb_size-- > 0)
			command(io, "rb");
	}
	else
	{
		while (rrr--)
			command(io, "rrr");
		while (ra_size-- > 0)
			command(io, "rra");
		while (rb_size-- > 0)
			command(io, "rrb");
	}
}

void	b_to_a(t_info *io, int size)
{
	t_solve	sol;

	if (size <= 3)
	{
		small_sort_b(io, size);
		return ;
	}
	init_solve(&sol, io->b, size);
	while (size--)
	{
		if (io->b->top->data < sol.pivot1)
			sol.rb += command(io, "rb");
		else
		{
			sol.pa += command(io, "pa");
			if (io->a->top->data < sol.pivot2)
				sol.ra += command(io, "ra");
		}
	}
	a_to_b(io, sol.pa - sol.ra);
	raise_rotate(io, sol.ra, sol.rb);
	a_to_b(io, sol.ra);
	b_to_a(io, sol.rb);
}

void	a_to_b(t_info *io, int size)
{
	t_solve	sol;

	if (size <= 3)
	{
		small_sort_a(io, size);
		return ;
	}
	init_solve(&sol, io->a, size);
	while (size--)
	{
		if (io->a->top->data >= sol.pivot2)
			sol.ra += command(io, "ra");
		else
		{
			sol.pb += command(io, "pb");
			if (io->b->top->data >= sol.pivot1)
				sol.rb += command(io, "rb");
		}
	}
	raise_rotate(io, sol.ra, sol.rb);
	a_to_b(io, sol.ra);
	b_to_a(io, sol.rb);
	b_to_a(io, sol.pb - sol.rb);
}
