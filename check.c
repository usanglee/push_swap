#include "push_swap.h"

int				is_space(int c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int				ft_atol(const char *str)
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

void		check_isdigit(char **split)
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
				print_error("check_isdigit #1");
			if (digit_flag == 0 && split[i][j] == '0' && \
			split[i][j + 1] != '\0')
				print_error("check_isdigit #2");
			if (!ft_isdigit(split[i][j]) && \
				!(split[i][j] == '-'))
				print_error("check_isdigit #3");
			j++;
		}
		i++;
	}
}

void		check_duplicate(t_info *io)
{
	int		i;
	int		j;

	i = 0;
	while (i < io->len_arg - 1)
	{
		j = i + 1;
		if (io->arr[i] == io->arr[j])
			print_error("check_duplicate");
		i++;
	}
}

int		check_sort(t_deque *deq)
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
