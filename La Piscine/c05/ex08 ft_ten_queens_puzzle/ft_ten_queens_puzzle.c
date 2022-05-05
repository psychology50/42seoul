/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:35:43 by jayang            #+#    #+#             */
/*   Updated: 2022/02/10 21:53:30 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    position_print(int *col) // 출력 함수
{
        int     i;
        char    result;

        i = 0;
        while (i < 10)
        {
                result = col[i] + '0'; // char type으로 치환시켜 전체 출력
                write(1, &result, 1);
                i++;
        }
        write(1, "\n", 1); // 개행
}

int     ft_abs(int nb) // 절댓값,, 굳이 예외처리 해줄 필요가 없어서 간단한 기능만 구현.
{
        if (nb < 0)
                nb *= -1;
        return (nb);
}

int     in_valid(int idx, int *col) // 배치가 유효한가?
{                                   // 같은 행이면 안 되고, 대각선 방향에 있으면 안 된다
        int check;

        check = 0;
        while (check < idx) // 검사하기 직전까지 놨었던 퀸의 경로 탐색
        {
                if (col[check] == col[idx] || \ // 같은 행에 존재하는가?
                    ft_abs(col[check] - col[idx]) == ft_abs(check - idx))
										// 대각선 상에 존재하는가?
										// col[check] - col[idx] => 이전 퀸들이 배치된 row 차이 비교
										// (check - idx) => column 차이 비교.
										// 두 값의 절댓값이 같다면 대각선 상에 존재함을 의미한다!
                        return (0);
                check++;
        }
        return (1); // 만약 위 조건에서 걸리지 않으면 1 리턴하고 퀸을 배치
}

int     queens_gambit(int idx, int *col)
{
        int row;
        int cnt;

        row = 0;
        cnt = 0; // 리턴값 ( = 배치가 완료됐었던 횟수)
        while (row < 10) // 열 이동
        {
                col[idx] = row; // 퀸을 해당 row에 배치 시켜 봄.
                if (in_valid(idx, col)) // 배치가 유효한지 검사
                {
                        if (idx == 9) // 마지막 열까지 배치가 성공한 경우에만 실행
                        {
                                position_print(col); // 배치 완료된 결과 출력
                                return (1); // 성공했으므로 1 리턴해서 더해줌
                        }
                        else
                                cnt += queens_gambit(idx + 1, col);
																// 배치가 덜 끝났다면 다음 row의 퀸을 배치 시작
                }
                row++;
        }
        return (cnt);
}

int     ft_ten_queens_puzzle(void)
{
				/*
					시작 하기에 앞서...
					해당 코드는 '배열[column] = row' 라는 개념으로 작성하였습니다.
					즉, col[0] = 0  =>  "0번 행, 0번 열에 퀸이 있다."  
				*/
        int     col[10]; // 0~9 까지의 1차원 배열을 생성.
        int     cnt;
        int     size;

        size = 0;
        while (size < 10)
        {
                col[size] = 0; // 퀸을 모두 0번 째 행에 나열함.
                size++;
        }
        cnt = queens_gambit(0, col); // 배치 시작
        return (cnt);
}