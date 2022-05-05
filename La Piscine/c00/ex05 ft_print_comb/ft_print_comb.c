#include <unistd.h>

void	arr_plus(char *arr)
{
	if (arr[2]++ == 57)
	{
		arr[2] = 48;
		arr[1]++;
	}
}

void	ft_print_comb(void)
{
	char	arr[3];

	arr[0] = 48;
	arr[1] = 48;
	arr[2] = 48;
	while (arr[0] <= 57)
	{
		if (arr[0] < arr[1] && arr[1] < arr[2])
		{
			write(1, arr, 1);
			write(1, arr + 1, 1);
			write(1, arr + 2, 1);
			if (arr[0] != 55)
			{
				write(1, ", ", 2);
			}
		}
		arr_plus(arr);
		if (arr[1] == 57)
		{
			arr[1] = 48;
			arr[0]++;
		}
	}
}