#include <unistd.h>

void	print(int num1, int num2)
{
	char	value1;
	char	value2;
	char	value3;
	char	value4;

	value1 = num1 / 10 + '0';
	value2 = num2 / 10 + 48;
	value3 = num1 % 10 + 48;
	value4 = num2 % 10 + 48;
	write(1, &value1, 1);
	write(1, &value3, 1);
	write(1, " ", 1);
	write(1, &value2, 1);
	write(1, &value4, 1);
	if (!((num1 == 98) && (num2 == 99)))
	{
		write(1, ", ", 2);
	}
}

int	recurive(int num1, int num2)
{
	while (num2 < 100)
	{
		if (num2 > num1)
		{
			print(num1, num2);
		}
		num2++;
	}
	if (num1 == 99)
	{
		return (0);
	}
	return (recursive(num1 + 1, 0));
}

void	ft_print_comb2(void)
{
	recursive(0, 0);
}