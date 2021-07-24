/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:45:44 by ulee              #+#    #+#             */
/*   Updated: 2021/07/25 00:42:24 by ulee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_deque(t_info *io)
{
	io->a = ext_malloc(1, sizeof(t_deque));
	io->b = ext_malloc(1, sizeof(t_deque));
}

int	pre_launch(t_info *io)
{
	check_isdigit(io->split);
	make_deque(io);
	io->arr = make_arr(io->a, io->a->size);
	quick_sort(io->arr, 0, io->len_arg - 1);
	check_duplicate(io);
	return (0);
}

void	print_ok_ko(t_info *io, int rd)
{
	if (rd == 0)
	{
		if (check_sort(io->a) == 1)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
}

int	command_checker(t_info *io, char *str)
{
	if (!ft_strcmp(str, "sa"))
		swap(io->a, ' ');
	else if (!ft_strcmp(str, "sb"))
		swap(io->b, ' ');
	else if (!ft_strcmp(str, "ss"))
		swap_both(io, 0);
	else if (!ft_strcmp(str, "pa"))
		push(io->b, io->a, ' ');
	else if (!ft_strcmp(str, "pb"))
		push(io->a, io->b, ' ');
	else if (!ft_strcmp(str, "rra"))
		reverse(io->a, ' ');
	else if (!ft_strcmp(str, "rrb"))
		reverse(io->b, ' ');
	else if (!ft_strcmp(str, "rrr"))
		reverse_both(io, 0);
	else if (!ft_strcmp(str, "ra"))
		rotate(io->a, ' ');
	else if (!ft_strcmp(str, "rb"))
		rotate(io->b, ' ');
	else if (!ft_strcmp(str, "rr"))
		rotate_both(io, 0);
	else
		print_error();
	return (1);
}

int	main(int ac, char **av)
{
	t_info	io;
	int		rd;
	char	*line;

	init_deque(&io);
	if (ac <= 1)
		return (0);
	if (ac == 2)
		ac_2(&io, av[1]);
	else
		ac_many(&io, ac - 1, av + 1);
	pre_launch(&io);
	rd = get_next_line(0, &line);
	while (rd > 0)
	{
		command_checker(&io, line);
		free(line);
		rd = get_next_line(0, &line);
	}
	print_ok_ko(&io, rd);
	deque_free(io.a);
	deque_free(io.b);
	free(io.a);
	free(io.b);
	return (0);
}
