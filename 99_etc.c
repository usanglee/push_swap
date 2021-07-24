/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99_etc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:21:57 by ulee              #+#    #+#             */
/*   Updated: 2021/07/24 21:37:11 by ulee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	*ext_malloc(size_t n, size_t size)
{
	void	*ret;

	ret = (char *)malloc(size * n);
	if (!ret)
		print_error();
	ft_bzero(ret, (n * size));
	return (ret);
}

void	swap_2(t_deque *deque)
{
	t_node	*top_node;

	top_node = deque->top;
	deque->top = deque->bottom;
	deque->bottom = top_node;
	deque->top->prev = NULL;
	deque->bottom->prev = deque->top;
	deque->top->next = deque->bottom;
	deque->bottom->next = NULL;
	return ;
}

void	push_general(t_deque *src, t_deque *dest)
{
	t_node	*top_node;

	if (dest->size == 0)
	{
		dest->top = src->top;
		dest->bottom = src->top;
		src->top = src->top->next;
		dest->top->next = NULL;
	}
	else
	{
		top_node = src->top;
		src->top = src->top->next;
		src->top->prev = NULL;
		top_node->next = dest->top;
		dest->top->prev = top_node;
		dest->top = top_node;
	}
	return ;
}
