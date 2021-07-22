/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_make.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:21:30 by ulee              #+#    #+#             */
/*   Updated: 2021/07/23 02:58:19 by ulee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(int c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	return (0);
}

long long	ft_atol(const char *str)
{
	long long	num;
	int			is_minus;

	is_minus = 0;
	while (is_space(*str))
		str++;
	if (*str == '-')
		is_minus = 1;
	if (*str == '-' || *str == '+')
		str++;
	num = 0;
	while (ft_isdigit(*str))
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	if (is_minus)
		num *= -1;
	return (num);
}

void	make_deque(t_info *io)
{
	int			i;
	long long	num;

	i = 0;
	while (i < io->len_arg)
	{
		num = ft_atol(io->split[i]);
		if (num < -2147483648 || num > 2147483647)
			print_error();
		push_back(io->a, node_new((int)num));
		i++;
	}
	two_arr_free(io->split);
}

int	*make_arr(t_deque *deq, int size)
{
	t_node	*temp;
	int		i;
	int		*arr;

	temp = deq->top;
	arr = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		arr[i++] = temp->data;
		temp = temp->next;
	}
	return (arr);
}
