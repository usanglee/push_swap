/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:21:27 by ulee              #+#    #+#             */
/*   Updated: 2021/07/23 02:58:13 by ulee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_isdigit(char **split)
{
	int		i;
	int		j;
	int		digit_flag;

	i = 0;
	while (split[i])
	{
		j = 0;
		digit_flag = 0;
		while (split[i][j])
		{
			if ('1' <= split[i][j] && split[i][j] <= '9')
				digit_flag = 1;
			if (split[i][j] == '-' && j != 0)
				print_error();
			if (digit_flag == 0 && split[i][j] == '0' && \
			split[i][j + 1] != '\0')
				print_error();
			if (!ft_isdigit(split[i][j]) && \
				!(split[i][j] == '-'))
				print_error();
			j++;
		}
		i++;
	}
}

void	check_duplicate(t_info *io)
{
	int		i;
	int		j;

	i = 0;
	while (i < io->len_arg - 1)
	{
		j = i + 1;
		if (io->arr[i] == io->arr[j])
			print_error();
		i++;
	}
}

int	check_sort(t_deque *deq)
{
	int			i;
	long long	before;
	t_node		*temp;

	i = 0;
	before = -2147483649;
	temp = deq->top;
	while (temp)
	{
		if (before > temp->data)
			return (0);
		before = temp->data;
		temp = temp->next;
	}
	return (1);
}
