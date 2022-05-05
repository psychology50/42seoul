#include <unistd.h>

void	ft_putchar_ptr(char	*input[])
{
	int	idx;

	idx = 1;
	while (input[idx])
	{
		while (*input[idx])
		{
			write(1, input[idx], 1);
			input[idx]++;
		}
		idx++;
		write(1, "\n", 1);
	}
}

void	swap_ptr(char **ptr1, char **ptr2)
{
	char	*temp;

	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

int	ft_strcmp(char  *s1, char *s2) // 알파벳 순 정렬을 위해 비교
{
	int	i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]); // 아스키 값을 비교해서 return
}

int	main(int argc, char *argv[])
{
	int i;
	int j;

	i = 0;
	while (i < argc - 1)
	{
		j = 1;
		while (j < argc - 1 - i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0) // 양수가 나오면 swap
			{
				swap_ptr(argv + j, argv + j + 1); // *argv 주소값을 가진 argv 주소 보냄
			}
			j++;
		}
		i++;
	}
	ft_putchar_ptr(argv);
	return (0);
}