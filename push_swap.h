/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:54:16 by ulee              #+#    #+#             */
/*   Updated: 2021/06/07 21:47:25 by ulee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct		s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct		s_deque
{
	t_node	*top;
	t_node	*bottom;
	int				size;
}					t_deque;

typedef struct		s_solve
{
	int pivot1;
	int pivot2;
	int ra;
	int rb;
	int pa;
	int pb;
}					t_solve;

typedef struct		s_info
{
	t_deque		*a;
	t_deque		*b;
	char		**split;
	int			len_arg;
	int			*arr;
}					t_info;

t_node	*node_new(int num);
t_node	*list_last(t_node *li);
void	list_add(t_node **li, t_node *new);

void	swap(t_deque *deque, int flag);

void	push(t_deque *src, t_deque *dest, int flag);

void	rotate(t_deque *deque, int flag);
void	reverse(t_deque *deque, int flag);
int		command(t_info *io, char *str);


void	swap_both(t_info *io);
void	rotate_both(t_info *io);
void	reverse_both(t_info *io);

void	print_error(char *str);

void	ac_2(t_info *io, char *av2);
void	ac_many(t_info *io, int len, char **av2);

int		ft_atol(const char *str);
void	check_isdigit(char **split);
int		check_sort(t_deque *deq);
int		r_check_sort(t_node *li);

void	make_deque(t_info *io);
int		*make_arr(t_deque *deq, int size);

void	two_arr_free(char **arr);
void	check_duplicate(t_info *io);

void	quick_sort(int *arr, int left, int right);

void	sort(t_info *io);
int		list_len(t_node *li);

void	set_cost_move(t_info *io);
void	set_cost_sort(t_info *io);
int		get_min_node(t_info *io);
void	raise_node(t_info *io);
void	sort_node(t_info *io);

void	*ext_malloc(size_t n, size_t size);

t_node	*node_new(int num);

void	push_front(t_deque *deque, t_node *node);
void	push_back(t_deque *deque, t_node *node);
void	remove_front(t_deque *deque);
void	remove_back(t_deque *deque);

void	b_to_a(t_info *info, int size);
void	a_to_b(t_info *info, int size);


void 	sort_arr(t_info *io);

void	mini_sort_132_a(t_info *io);
void	mini_sort_231_a(t_info *io);
void	mini_sort_312_a(t_info *io);
void	mini_sort_321_a(t_info *io);
void	mini_sort_3_a(t_info *io);

void	mini_sort_123_b(t_info *io);
void	mini_sort_213_b(t_info *io);
void	mini_sort_132_b(t_info *io);
void	mini_sort_3_b(t_info *io);


#endif
