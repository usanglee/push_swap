/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_node_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:21:20 by ulee              #+#    #+#             */
/*   Updated: 2021/07/22 23:33:38 by ulee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_new(int num)
{
	t_node	*node;

	node = ext_malloc(1, sizeof(t_node));
	node->data = num;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	push_front(t_deque *deque, t_node *node)
{
	if (deque == NULL || node == NULL)
		return ;
	if (deque->size == 0)
	{
		deque->top = node;
		deque->bottom = node;
		deque->size++;
		return ;
	}
	node->next = deque->top;
	deque->top->prev = node;
	node->prev = NULL;
	deque->top = node;
	deque->size++;
}

void	push_back(t_deque *deque, t_node *node)
{
	if (deque == NULL || node == NULL)
		return ;
	if (deque->size == 0)
	{
		deque->top = node;
		deque->bottom = node;
		deque->size++;
		return ;
	}
	deque->bottom->next = node;
	node->prev = deque->bottom;
	node->next = NULL;
	deque->bottom = node;
	deque->size++;
}

void	remove_front(t_deque *deque)
{
	if (deque == NULL)
		return ;
	if (deque->size == 1)
	{
		deque->top = NULL;
		deque->bottom = NULL;
		deque->size--;
		return ;
	}
	deque->top = deque->top->next;
	deque->top->prev = NULL;
	deque->size--;
}

void	remove_back(t_deque *deque)
{
	if (deque == NULL)
		return ;
	if (deque->size == 1)
	{
		deque->top = NULL;
		deque->bottom = NULL;
		return ;
	}
	deque->bottom = deque->bottom->prev;
	deque->bottom->next = NULL;
	deque->size--;
}
