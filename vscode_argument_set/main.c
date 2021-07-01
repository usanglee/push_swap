#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

// ================================== Libft 함수들 =================================================

void 	*ft_memcpy(void *copy, const void *origin, size_t byte_size)
{
	size_t	i;

	if (copy == NULL && origin == NULL)
		return (copy);
	i = 0;
	while (i < byte_size)
	{
		((unsigned char *)copy)[i] = ((const unsigned char *)origin)[i];
		i++;
	}
	return (copy);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

size_t	ft_strlcpy(char *copy, const char *origin, size_t char_count)
{
	size_t	i;

	if (copy == NULL && origin == NULL)
		return (0);
	i = 0;
	if (char_count > 0)
	{
		while (i < (char_count - 1) && origin[i])
		{
			copy[i] = origin[i];
			i++;
		}
		copy[i] = '\0';
	}
	return (ft_strlen(origin));
}

char	*ft_strdup(const char *s)
{
	char	*result;
	int		len;

	len = ft_strlen(s);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s, len);
	result[len] = 0;
	return (result);
}

int	itoa_len(int num)
{
	int		len;

	len = 1;
	if (num < 0)
		len++;
	while ((num / 10) != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int num)
{
	char		*result;
	long long	num_cast;
	int			is_minus;
	int			len;

	is_minus = 0;
	num_cast = num;
	len = itoa_len(num);
	if (num_cast < 0)
	{
		num_cast *= -1;
		is_minus = 1;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len--] = 0;
	while (len >= 0)
	{
		result[len--] = num_cast % 10 + '0';
		num_cast /= 10;
	}
	if (is_minus)
		result[0] = '-';
	return (result);
}

// ============================================ 끝 ===============================================


int 	*return_arr_random(char **av)
{
	int random = 0;
	int *check_plus;
	int *check_minus;
	int *ret;
	int count;
	int range;
	int index;

	srand(time(NULL));
	range = atoi(av[1]);
	index = 0;
	count = 0;
	check_plus = (int *)calloc(sizeof(int), (range / 2 + 1));
	check_minus = (int *)calloc(sizeof(int), (range / 2 + 1));
	ret = (int *)calloc(sizeof(int), (range + 1));
	if (check_plus == NULL || check_minus == NULL)
		return (NULL);

	while (count < range)
	{
		random = rand() % range - (range / 2);
		if (random < 0)
		{
			if (check_minus[-random] == 0)
			{
				ret[index++] = random;
				check_minus[-random] = 1;
				count++;
			}
		}
		else
		{
			if (check_plus[random] == 0)
			{
				ret[index++] = random;
				check_plus[random] = 1;
				count++;
			}
		}
	}
	free(check_minus);
	free(check_plus);
	return (ret);
}

void	input_num(char **buf, int num)
{
	char *itoa;

	itoa = ft_itoa(num);
	while (*itoa != '\0')
	{
		**buf = *itoa;
		(*buf)++;
		itoa++;
	}
	**buf = ' ';
	(*buf)++;
}

void	input_str(char **buf, char *str)
{
	while (*str != '\0')
	{
		**buf = *str;
		(*buf)++;
		str++;
	}
}

int		check_arg(int ac, char *av)
{
	int i;

	if (ac != 2)
	{
		printf("인수는 1개만(원하는 랜덤 숫자 갯수) 넣어주세요.");
		return (1);
	}
	if (av[0] == '-')
	{
		printf("인수는 양수만 가능합니다.");
		return (1);
	}
	if (atoi(av) > 5000)
	{
		printf("인수는 5000 이하만 가능합니다.");
		return (1);
	}
	i = 0;
	while (av[i])
	{
		if (!('0' <= av[i] && av[i] <= '9') && av[i] !='-')
		{
			printf("숫자 인수를 넣어주세요.");
			return (1);
		}
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int 	fd;
	int 	fd2;
	char 	*buf;
	char 	*arg_start;
	char 	*arg_end_after;
	int		*arr_random;
	int		range;
	int 	i;

	if (check_arg(ac, av[1]) == 1)
		return (1);
	buf = (char *)malloc(sizeof(char) * 3000000);
	if (buf == NULL)
		return (1);
	fd = open("./.vscode/launch.json", O_RDWR);
	if (fd == -1)
	{
		printf("파일이 없네요. 기본 파일 경로는 ./.vscode/launch.json입니다.");
		return (1);
	}
	read(fd, buf, 3000000);
	close(fd);

	fd2 = open("./.vscode/launch.json", O_RDWR | O_CREAT | O_TRUNC);
	if (fd2 == -1)
	{
		printf("파일이 없네요. 기본 파일 경로는 ./.vscode/launch.json입니다.");
		return (1);
	}
	i = 0;
	while (buf[i])
	{
		if (strncmp(&buf[i], "args", 4) == 0)
		{
			arg_start = ft_strchr(&buf[i], '[') + 1;
			arg_end_after = ft_strdup(ft_strchr(arg_start, ']'));
			if (arg_end_after == NULL)
				return (1);
			break;
		}
		i++;
	}
	range = atoi(av[1]);
	arr_random = return_arr_random(av);
	i = 0;
	while (i < range)
	{
		if (i == 0)
			input_str(&arg_start, "\n\t\t\t\t\"");
		input_num(&arg_start, arr_random[i]);
		i++;
	}
	free(arr_random);

	arg_start--;
	input_str(&arg_start, "\"\n\t\t\t");
	ft_strlcpy(arg_start, arg_end_after, ft_strlen(arg_end_after) + 1);
	free(arg_end_after);

	write(fd2, buf, ft_strlen(buf));
	free(buf);
	close(fd2);
	return (0);
}
