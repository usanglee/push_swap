/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:21:35 by ulee              #+#    #+#             */
/*   Updated: 2021/07/25 00:26:15 by ulee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_deque *deque, int flag)
{
	t_node	*top_node;

	if (deque == NULL)
		return ;
	if (deque->size == 0 || deque->size == 1)
		return ;
	if (deque->size == 2)
		swap_2(deque);
	else
	{
		top_node = deque->top;
		deque->top = top_node->next;
		deque->top->prev = NULL;
		top_node->next = deque->top->next;
		deque->top->next->prev = top_node;
		deque->top->next = top_node;
		top_node->prev = deque->top;
	}
	if (flag == 'a')
		ft_printf("sa\n");
	else if (flag == 'b')
		ft_printf("sb\n");
}

void	push(t_deque *src, t_deque *dest, int flag)
{
	if (src == NULL || dest == NULL)
		return ;
	if (src->size == 0)
		return ;
	if (src->size == 1)
	{
		if (dest->size == 0)
			dest->bottom = src->top;
		else
		{
			dest->top->prev = src->top;
			src->top->next = dest->top;
		}
		dest->top = src->top;
		src->top = NULL;
		src->bottom = NULL;
	}
	else
		push_general(src, dest);
	src->size--;
	dest->size++;
	if (flag == 'a')
		ft_printf("pa\n");
	else if (flag == 'b')
		ft_printf("pb\n");
}

void	rotate(t_deque *deque, int flag)
{
	if (deque == NULL)
		return ;
	if (deque->size == 0 || deque->size == 1)
		return ;
	deque->top = deque->top->next;
	deque->bottom->next = deque->top->prev;
	deque->bottom->next->prev = deque->bottom;
	deque->top->prev = NULL;
	deque->bottom = deque->bottom->next;
	deque->bottom->next = NULL;
	if (flag == 'a')
		ft_printf("ra\n");
	else if (flag == 'b')
		ft_printf("rb\n");
}

void	reverse(t_deque *deque, int flag)
{
	if (deque == NULL)
		return ;
	if (deque->size == 0 || deque->size == 1)
		return ;
	deque->top->prev = deque->bottom;
	deque->bottom->next = deque->top;
	deque->bottom = deque->bottom->prev;
	deque->bottom->next = NULL;
	deque->top = deque->top->prev;
	deque->top->prev = NULL;
	if (flag == 'a')
		ft_printf("rra\n");
	else if (flag == 'b')
		ft_printf("rrb\n");
}

int	command(t_info *io, char *str)
{
	if (!ft_strcmp(str, "sa"))
		swap(io->a, 'a');
	else if (!ft_strcmp(str, "sb"))
		swap(io->b, 'b');
	else if (!ft_strcmp(str, "ss"))
		swap_both(io, 1);
	else if (!ft_strcmp(str, "pa"))
		push(io->b, io->a, 'a');
	else if (!ft_strcmp(str, "pb"))
		push(io->a, io->b, 'b');
	else if (!ft_strcmp(str, "rra"))
		reverse(io->a, 'a');
	else if (!ft_strcmp(str, "rrb"))
		reverse(io->b, 'b');
	else if (!ft_strcmp(str, "rrr"))
		reverse_both(io, 1);
	else if (!ft_strcmp(str, "ra"))
		rotate(io->a, 'a');
	else if (!ft_strcmp(str, "rb"))
		rotate(io->b, 'b');
	else if (!ft_strcmp(str, "rr"))
		rotate_both(io, 1);
	else
		print_error();
	return (1);
}
