#include <unistd.h>

void	ft_putchar(char *arr, int len)
{
	int		i;
	char	output;

	i = 0;
	while (i < len)
	{
		output = arr[i] + '0';
		write(1, &output, 1);
		i++;
	}
	if (arr[0] != 10 - len)
	{
		write(1, ", ", 2);
	}
}
/*
[1] 출력 함수

     : 배열의 인덱스에 차례로 접근하여 문자로 치환해서 출력함. (’0’을 더함으로써 자동 형변환 유도)

     Q. “, “ 출력을 하지 않는 조건?

     A. n=1일 때, a[0] = 9 종료 ... n=2일 때, a[1] = 8 종료 ... ... ... n=9일 때, a[0] 종료

         또한 n이 최댓값에 도달했을 때에 조합 가능한 경우의 수가 하나밖에 없으므로

   arr[0]이 (10 - len)에 도달했을 때에 출력하지 않으면, 마지막에 호출이 되지 않는다.
*/

int	check_arr(char *arr, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] >= arr[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
[2] 크기 비교 함수

      : i와 i+1 번째 인덱스를 비교하여 한 번이라도 오름차순을 만족하지 않는 경우가 있으면 0리턴.
*/

void	create_arr(int *arr, int current, int max)
{
	int	i;

	if (current == max)
	{
		if (check_arr(arr, max))
		{
			my_putchar(arr, max);
		}
		return ;
	}
	i = 0;
	while (i <= 9)
	{
		arr[current] = i;
		create_arr(arr, current + 1, max);
		i++;
	}
}

/*
[3] 재귀함수 → 최초 배열 초기화와 element 수정을 담당한다.

      1. 우선 배열을 내가 사용할 만큼만 초기화를 시키고, 각 인덱스에 접근 가능하도록 세팅한다.

          (1) 문제는 max가 9인 경우에는 9중 반복문을 써야 한다는 소린데, 시간 복잡도 개념을 제외하더라도

                norminette가 날 죽이려고 달려들 것.

          (2) 그렇다면 반복문을 반복시킬 수 있는 재귀함수 사용 .... 쓰기 싫다 ............

      2. 탈출 조건

          (1) 현재 인덱스(current)가 한계점(max)에 도달했을 때, 오름차 순을 만족하는 경우 전부 출력하고 탈출

      3. 반복

          (1) current가 max에 도달하고 오름차순 조건이 만족한 모든 경우를 출력

          (2) current - 1 시점의 재귀로 돌아와서 current - 1의 인덱스 값을 1 추가 후

          (3) current를 다시 if문으로 밀어 넣는 시스템.

      4. 정리

           (1) 해당 함수는 n이 9라고 가정했을 때, 모든 인덱스에 0 0 0 0 0 0 0 0 0 ~ 9 9 9 9 9 9 9 9 9 삽입

           (2) 오름차순 조건에 만족했을 경우에만 if문이 실행되고 출력이 진행됨.
*/

void	ft_print_combn(int n)
{
	int	arr[9];

	create_arr(arr, 0, n);
}

/*
[4] main한테서 n값을 받고, int arr[9] 생성해서 [3] 함수로 던짐.

      Q. 굳이 int형 배열을 만든 이유?

      A. 각 자릿수의 값 비교를 용이하게 하기 위함. 출력은 문자로 치환하면 끝.
*/