/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 21:35:19 by ulee              #+#    #+#             */
/*   Updated: 2021/07/24 21:35:20 by ulee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_arr_free(char **arr)
{
	int		i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	deque_free(t_deque *deq)
{
	t_node	*temp;

	while (deq->top)
	{
		temp = deq->top->next;
		free(deq->top);
		deq->top = temp;
	}
}
