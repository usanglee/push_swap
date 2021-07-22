/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:21:33 by ulee              #+#    #+#             */
/*   Updated: 2021/07/22 23:38:34 by ulee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(int *arr, int left, int right)
{
	int		i;
	int		j;
	int		pivot;
	int		temp;

	i = left;
	j = right;
	pivot = arr[(left + right) / 2];
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = arr[i];
			arr[i++] = arr[j];
			arr[j--] = temp;
		}
	}
	if (left < j)
		quick_sort(arr, left, j);
	if (i < right)
		quick_sort(arr, i, right);
}
