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

typedef struct		s_li
{
	int				data;
	unsigned int	cost_move;
	unsigned int	cost_sort;
	int				reverse_move;
	int				reverse_sort;
	int				total_cost;
	int				rr_count;
	struct s_li		*prev;
	struct s_li		*next;
}					t_li;

typedef struct		s_info
{
	t_li *a;
	t_li *b;
	char	**split;
	int		len_arg;
	int		*arr;
}					t_info;

t_li	*list_new(int num);
t_li	*list_last(t_li *li);
void	list_add(t_li **li, t_li *new);

void	swap(t_li **li);
void	push(t_li **src, t_li **dest, int flag);
void	rotate(t_li **li, int flag);
void	reverse(t_li **li, int flag);
void	command(t_info *io, char *str);


void	swap_both(t_li **a, t_li **b);
void	rotate_both(t_li **a, t_li **b);
void	reverse_both(t_li **a, t_li **b);

void	print_error(char *str);

void		ac_2(t_info *io, char *av2);
void		ac_many(t_info *io, int len, char **av2);

int			ft_atol(const char *str);
void		check_isdigit(char **split);
int			check_sort(t_li *li);
int			r_check_sort(t_li *li);

void		make_list(t_info *io);
void		make_arr(t_info *io);


void		two_arr_free(char **arr);
void		check_duplicate(t_info *io);

void	sort_arr(int *arr, int left, int right);

void	sort(t_info *io);
int		list_len(t_li *li);

void		set_cost_move(t_info *io);
void			set_cost_sort(t_info *io);
int			get_min_node(t_info *io);
void		raise_node(t_info *io);
void		sort_node(t_info *io);


#endif
