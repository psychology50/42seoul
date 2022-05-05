#include <unistd.h>

int	minus(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			write(1, "2", 1);
			return (147483648);
		}
		return (-nb);
	}
	return (nb);
}
/*
[minus function]

1. nb의 부호를 판단
2. int 타입의 가장 작은 값 처리

int 자료형의 범위는 -2,147,483,68 ~ 2,148,483,67 이기 때문에

가장 작은 음수의 값이 들어올 경우, 따로 계산을 해주어야 한다.

위 코드에서는 nb가 -2,147,483,648일 경우에 -와 2를 먼저 출력시킨 다음

nb값으로 147,483,648을 리턴시켜 ft_putnbr 함수로 보냈다.
*/

void	ft_putnbr(int nb)
{
	int		temp;
	int		num_size;
	char	result;

	nb = minus(nb);
	temp = nb;
	num_size = 1;
	while (temp >= 10)
	{
		temp /= 10;
		num_size *= 10;
	}
	while (num_size > 0)
	{
		result = (char)(nb / num_size) + 48;
		nb %= num_size;
		num_size /= 10;
		write(1, &result, 1);
	}
}
/*
1. nb의 값을 복사한 temp값을 10으로 나누면서 num_size의 변수를 10씩 곱하여 자릿수 계산
2. 출력문에서 nb값을 num_size로 나눈 몫을 차례로 출력시킴
3. nb는 num_size의 나머지를 연산한 값을 재할당시키고, num_size 또한 10씩 나누어 자릿수를 맞춰 줌.
*/