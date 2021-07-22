/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99_etc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:21:57 by ulee              #+#    #+#             */
/*   Updated: 2021/07/23 02:58:32 by ulee             ###   ########.fr       */
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
