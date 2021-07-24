/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:54:16 by ulee              #+#    #+#             */
/*   Updated: 2021/07/24 20:40:37 by ulee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_deque
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_deque;

typedef struct s_solve
{
	int		pivot1;
	int		pivot2;
	int		ra;
	int		rb;
	int		pa;
	int		pb;
}					t_solve;

typedef struct s_info
{
	t_deque			*a;
	t_deque			*b;
	char			**split;
	int				len_arg;
	int				*arr;
}					t_info;

// 01_node_io
t_node		*node_new(int num);
void		push_front(t_deque *deque, t_node *node);
void		push_back(t_deque *deque, t_node *node);
void		remove_front(t_deque *deque);
void		remove_back(t_deque *deque);

// 02_argument
void		ac_2(t_info *io, char *av2);
void		ac_many(t_info *io, int len, char **av2);

// 03_check
void		check_isdigit(char **split);
void		check_duplicate(t_info *io);
int			check_sort(t_deque *deq);

// 04_make
int			is_space(int c);
long long	ft_atol(const char *str);
void		make_deque(t_info *io);
int			*make_arr(t_deque *deq, int size);

// 05_quick_sort
void		quick_sort(int *arr, int left, int right);

// 06_command
void		swap(t_deque *deque, int flag);
void		push(t_deque *src, t_deque *dest, int flag);
void		rotate(t_deque *deque, int flag);
void		reverse(t_deque *deque, int flag);
int			command(t_info *io, char *str);

// 07_command_both
void		swap_both(t_info *io, int c);
void		rotate_both(t_info *io, int c);
void		reverse_both(t_info *io, int c);

// 08_sort
void		init_solve(t_solve *sol, t_deque *deq, int size);
void		set_rrr_count(t_info *io, int *ra, int *rb, int *rrr);
void		raise_rotate(t_info *io, int ra_size, int rb_size);
void		b_to_a(t_info *io, int size);
void		a_to_b(t_info *io, int size);

// 09_small_sort
void		small_sort_a(t_info *io, int size);
void		small_sort_b(t_info *io, int size);

// 10_small_sort_3_a
void		small_sort_132_a(t_info *io);
void		small_sort_231_a(t_info *io);
void		small_sort_312_a(t_info *io);
void		small_sort_321_a(t_info *io);
void		small_sort_3_a(t_info *io);

// 11_small_sort_3_b
void		small_sort_123_b(t_info *io);
void		small_sort_213_b(t_info *io);
void		small_sort_132_b(t_info *io);
void		small_sort_3_b(t_info *io);

// 12_free
void		two_arr_free(char **arr);
void		deque_free(t_deque *deq);

// 99_etc
void		print_error(void);
void		*ext_malloc(size_t n, size_t size);
void		swap_2(t_deque *deque);
void		push_general(t_deque *src, t_deque *dest);

// checker
void		init_deque(t_info *io);
int			pre_launch(t_info *io);
void		print_ok_ko(t_info *io, int rd);
int			command_checker(t_info *io, char *str);

#endif
