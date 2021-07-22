/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:21:16 by ulee              #+#    #+#             */
/*   Updated: 2021/07/23 00:43:41 by ulee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_info	io;

	io.a = ext_malloc(1, sizeof(t_deque));
	io.b = ext_malloc(1, sizeof(t_deque));
	if (ac <= 1)
		return (0);
	if (ac == 2)
		ac_2(&io, av[1]);
	else
		ac_many(&io, ac - 1, av + 1);
	check_isdigit(io.split);
	make_deque(&io);
	io.arr = make_arr(io.a, io.a->size);
	quick_sort(io.arr, 0, io.len_arg - 1);
	check_duplicate(&io);
	if (check_sort(io.a) == 1)
		return (0);
	a_to_b(&io, io.a->size);
	return (0);
}
