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

void	push(t_node **src, t_node **dest, int flag);
void	rotate(t_node **li, int flag);
void	reverse(t_node **li, int flag);
void	command(t_info *io, char *str);


void	swap_both(t_node **a, t_node **b);
void	rotate_both(t_node **a, t_node **b);
void	reverse_both(t_node **a, t_node **b);

void	print_error(char *str);

void	ac_2(t_info *io, char *av2);
void	ac_many(t_info *io, int len, char **av2);

int		ft_atol(const char *str);
void	check_isdigit(char **split);
int		check_sort(t_node *li);
int		r_check_sort(t_node *li);

void	make_list(t_info *io);
void	make_arr(t_info *io);


void	two_arr_free(char **arr);
void	check_duplicate(t_info *io);

void	sort_arr(int *arr, int left, int right);

void	sort(t_info *io);
int		list_len(t_node *li);

void	set_cost_move(t_info *io);
void	set_cost_sort(t_info *io);
int		get_min_node(t_info *io);
void	raise_node(t_info *io);
void	sort_node(t_info *io);

void	*ft_salloc(size_t n, size_t size);

t_node	*node_new(int num);

void	push_front(t_deque *deque, t_node *node);
void	push_back(t_deque *deque, t_node *node);
void	remove_front(t_deque *deque);
void	remove_back(t_deque *deque);

#endif
